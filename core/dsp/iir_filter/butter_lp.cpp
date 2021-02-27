
// Copyrights Patrick 2020

#include "butter_lp.hpp"

namespace canal {
namespace dsp {
template<class T>
ButterLowPass<T>::ButterLowPass(int order_) : IIRBase<T>(order_) {
}

template<class T>
ButterLowPass<T>::ButterLowPass(int order_, const T& fc, const T& fs) :
    IIRBase<T>(order_, fc, fs) {
}

template<class T>
IIRBase<T>* ButterLowPass<T>::clone() const {
  return new ButterLowPass<T>(*this);
}

template<class T>
void ButterLowPass<T>::print() {
  std::cout <<"Filter order is:" << IIRBase<T>::get_order() << "\n";
}

template<class T>
void ButterLowPass<T>::design() {

  /*
    *****************************Step 1-COMPUTE COMPLEX POLES*********************
    Poles of analog filter:
    For Butterworth filter of order N with Omega_c = 1 rad/s, the poles
    are: p_analog = -sin(theta) + jcos(theta)

    *****************************Step 2-PREWARPING********************************
    Now, using the desired cut-off freq we find the analog frequency Fc. It is necessary to prewarp
     because the bilinear does not map F to f linearly. E.g fs=100Hz, fc=20Hz should give FC=23.12 Hz

     *****************************Step 3-SCALE POLES******************************
     Scale s-plane poles by 2*PI*Fc (poles computed above give Omega_c = 1 rads/sec or 1/(2*Pi) Hz
     Multiplying by  2*PI*Fc sccales analog filter cutt-off to Fc and digital filter cut-off to fc.

     ***********************Step 4-GET DIGITAL FILTER COEFFIECIENTS******************
     Now transform poles from s to z-plane using bilinear transform
     That is, find coefficients of filter   
  */
  T g, Fc, fc = IIRBase<T>::get_cutoff_freq(), fs = IIRBase<T>::get_samp_freq();
  int n = IIRBase<T>::get_order();
  canal::math::Vector<T> a, b, q(n, -1.0);
  canal::math::Complex<T> c(1, 0), val, w(0), w1(2*fs);
  canal::math::Vector<T> theta(n), k("linspace", T(0), T(n-1), n);
  canal::math::Vector<canal::math::Complex<T>> p_analog(n), p(n, c), cc;

  
  theta = ((T(2)*k)+T(1))*(M_PI/(T(2)*n));
  p_analog = canal::math::real2complex(-canal::math::sin(theta),
                                        canal::math::cos(theta));
  
  Fc = fs/M_PI * std::tan(M_PI * fc / fs);
  
  p_analog = p_analog*(canal::math::Complex<T>(T(2)*M_PI*Fc));
  
  p = canal::math::elem_div(canal::math::Complex<T>(1) +
                             (p_analog/(2*fs)),
                             canal::math::Complex<T>(1) -
                             p_analog/(2*fs));

  a = canal::math::cplex2real(canal::math::poly(p));
  b = canal::math::poly(q);
  g = canal::math::sum(a)/canal::math::sum(b);
  b = g*b;
  IIRBase<T>::set_pole_coeffs(a);
  IIRBase<T>::set_zero_coeffs(b);
  
}




// Ordinary functions
/*
template<typename T>
const dst::list< canal::math::Vector<T> > get_coeff(const IIRBase<T>) {
  std::cout<< "Not yet implementd" <<"\n";
  dst::list<canal::math::Vector<T>> coef(2);
  coef.set(0, IIRBase<T>::get_den_coeffs());
  coef.set(1, IIRBase<T>::get_num_coeffs());
  return coef;
}
*/




}
}
