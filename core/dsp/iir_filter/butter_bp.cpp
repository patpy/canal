
// Copyrights Patrick 2020

#include "butter_bp.hpp"

namespace canal {
namespace dsp {

template<class T>
ButterworthBandPass<T>::ButterworthBandPass(const int order_) :
    IIRBase<T>(order_, T(0.7)) {
  
}

template<class T>
ButterworthBandPass<T>::ButterworthBandPass(const int order_,
                                            const T& f_center_,
                                            const T& bandwidth_,
                                            const T& fs):IIRBase<T>
                                            (order_, f_center_),
                                            band_width(bandwidth_) {
}

template<class T>
void ButterworthBandPass<T>::design() {
/*
***********************************************************************************
1) Find poles of lowpass analog prototype filter with omega_c = 1 rad/sec
2) Given the upper and lower -3dB frequencis of the digital bandpass, find the correspo
   nding frequencies of the digital bandpass filter(pre-warping)
3) Transform the analog lowpass to analog bandpass poles
4) Transform poles from s-plane to the z-plane, using bilinear transform
5) Add N zeros at z = -1 and N zeros at z = +1, where N is the order of the lowpass
   filter prototype
6) Convert ples and zeros to polynomials with coefficients a_n and b_n   

***********************************************************************************
*/

  T g, h, f0, f1, f2, F0, F1, F2, BW_hz;
T f_center = IIRBase<T>::get_cutoff_freq();
T fs = IIRBase<T>::get_samp_freq();
int n = IIRBase<T>::get_order();
canal::math::Vector<T>a, b, q(n, T(1));
canal::math::Complex<T> c(1, 0), val, w(0), w1(2*fs);
canal::math::Vector<T> theta(n), k("linspace", T(0), T(n-1), n);
canal::math::Vector<int> kk("linspace", 0, n, n+1);
canal::math::Vector<canal::math::Complex<T>> p_analog(n), p(n, c), pa,
    cc, alpha, beta;

theta = ((T(2)*k)+T(1))*(M_PI/(T(2)*n));

// poles of lpf with cut-off freq of 1 rad/sec
p_analog = canal::math::real2complex(-canal::math::sin(theta),
                                      canal::math::cos(theta));

/* Given upper and -3 dB frequencies find
   corresponding frequencies of analog bandpass filter
*/
f1 = f_center - band_width/(T(2));
f2 = f_center + band_width/(T(2));

throw_assert(f2 <= fs/2,
             "fcenter + bandwidth/2 must be less than sampling freq/2");

throw_assert(f1 >= 0,
             "fcenter - bandwidth/2 must be less than sampling freq/2");

// find poles of a butterworth lpf with omega_c = 1 rad/s
theta = ((T(2)*k) + T(1))*(M_PI/(T(2)*n));

// tranform to poles 
p_analog = canal::math::real2complex(-canal::math::sin(theta),
                                      canal::math::cos(theta));

/* pre-warp f0, f1 and f2 to take nonlinearity
of the bilinear transform into account.
*/
F1 = fs/M_PI * std::tan(M_PI*f1/fs);
F2 = fs/M_PI * std::tan(M_PI*f2/fs);

// The prewarped -3 dB bandwidth
BW_hz = F2 - F1; 

// Hz geometric mean frequency
F0 = std::sqrt(F1/F2);

// transform poles for bpf centered at W0
// alpha and beta vectors are of length N; pa is a vector of length 2N
alpha = BW_hz/F0 * 1/2*p_analog;
beta = canal::math::sqrt(1 - ((BW_hz/F0*p_analog/2)*(BW_hz/F0*p_analog/2)));
pa = 2*M_PI*F0*(canal::math::concat_vec(
    alpha+canal::math::real2complex(beta),
    alpha-canal::math::real2complex(beta)));

// find poles and zeros of digital filter
p = canal::math::elem_div((1 + pa/(T(2)*fs)), (1 - pa/(T(2)*fs)));
q = canal::math::concat_vec(T(-1)*q, q);

// convert poles and zeros to numerator and denominator polynomials
a = canal::math::cplex2real(canal::math::poly(p));
b = poly(q);

// scale coeffs so that amplitude is 1.0 at f0
f0 = std::sqrt(f1*f2);


}



}
}
