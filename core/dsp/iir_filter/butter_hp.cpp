
// Copyrights Patrick 2020

#include "butter_hp.hpp"

namespace canal {
namespace dsp {
template<class T>
ButterHighPass<T>::ButterHighPass(int order_) : IIRBase<T>(order_) {
}

template<class T>
ButterHighPass<T>::ButterHighPass(int order_, const T& fc, const T& fs) :
    IIRBase<T>(order_, fc, fs) {
}

template<class T>
IIRBase<T>* ButterHighPass<T>::clone() const {
  return new ButterHighPass<T>(*this);
}

template<class T>
void ButterHighPass<T>::print() {
  std::cout <<"Filter order is:" << IIRBase<T>::get_order() << "\n";
}

template<class T>
void ButterHighPass<T>::design() {

  /*
    *****************************Step 1-COMPUTE COMPLEX POLES*********************
    Poles of analog prototype low pass filter:
    For Butterworth filter of order N with Omega_c = 1 rad/s.
    poles of the analog lowpass prototype are: p_analog = -sin(theta) + jcos(theta)

    *****************************Step 2-PREWARPING********************************
    Given the -3dB frequency  of the digital highpass  filter, find the corresponding frequency of the analog highpass filter (pre-warping)
    First, adjust (prewarp) the analog frquency to take nonlinearty of the bilinear transform
    into account

    *******************************Step 3-TRANSFORM POLES*****************************
    Transform the analog lowpass poles to analog highpass poles:
    For each p_analog
    p_a = 2*pi*F_c/p_analog

    ***********************Step 4-GET DIGITAL FILTER COEFFIECIENTS******************
     Now transform poles from s to z-plane using bilinear transform
     That is, find coefficients of filter

     **************************Step 5-Add N ZEROS AT Z=1***********************************
     The N_th-order highpass filter has N zeros at omega = 0 (z = exp(j0) = 1 )
  */

  T g, Fc, fc = IIRBase<T>::get_cutoff_freq(), fs = IIRBase<T>::get_samp_freq();
  int n = IIRBase<T>::get_order();
  canal::math::Vector<T> a, b, q(n, T(1));
  canal::math::Complex<T> c(1, 0), val, w(0), w1(2*fs);
  canal::math::Vector<T> theta(n), k("linspace", T(0), T(n-1), n);
  canal::math::Vector<int> kk("linspace", 0, n, n+1);
  canal::math::Vector<canal::math::Complex<T>> p_analog(n), p(n, c), cc;

  theta = ((T(2)*k)+T(1))*(M_PI/(T(2)*n));

  
  // poles of lpf with cutt-off freq of 1 rads/sec
  p_analog = canal::math::real2complex(-canal::math::sin(theta),
                                        canal::math::cos(theta));
  // transform to poles of high pass filter
  Fc = fs/M_PI * std::tan(M_PI * fc / fs);
  p_analog = canal::math::Complex<T>(T(2)*M_PI*Fc)/p_analog;

  // poles by bilinear transformation
  p = canal::math::elem_div(canal::math::Complex<T>(1) +
                            (p_analog/canal::math::Complex<T>(2*fs)),
                            canal::math::Complex<T>(1) -
                            p_analog/canal::math::Complex<T>(2*fs));

   
  // Convert poles and zeros to polynomials with coefficients a_n and b_n
  // a must be real
  a = canal::math::cplex2real(canal::math::poly(p));
  b = canal::math::poly(q);
  
  // Because the filter is highpass, we want H(z) to have gain of 1 at f = fs/2
  // (at omega = pi, z = exp(jpi) = -1
  // So amplitude scale factor is computed as follows:
  g = canal::math::sum(canal::math::elem_mult(canal::math::power(T(-1), kk), a))/ canal::math::sum(canal::math::elem_mult(canal::math::power(T(-1), kk), b));
  
  // amplitude scale factor
  b = g * b;
  
  IIRBase<T>::set_pole_coeffs(a);
  IIRBase<T>::set_zero_coeffs(b);
  
}





}
}
