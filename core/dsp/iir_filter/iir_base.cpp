
#include "iir_base.hpp"
namespace canal {
namespace dsp {
template<class T>
IIRBase<T>::IIRBase(int order_) : order(order_) {
  cut_off_freq = T(0.2);
  samp_freq = T(1);
}

template<class T>
IIRBase<T>::IIRBase(int order_, const T& fc, const T& fs) : order(order_),
                                                            cut_off_freq(fc),
                                                            samp_freq(fs) {
}


template<class T>
const int& IIRBase<T>::get_order() const {
  return order;
}

template<class T>
const T IIRBase<T>::get_cutoff_freq() const {
  return cut_off_freq;
}


template<class T>
const T IIRBase<T>::get_samp_freq() const {
  return samp_freq;
}

template<class T>
const canal::math::Vector<T>& IIRBase<T>::get_zero_coeffs() const {
  return zero_poly_coeff;
}

template<class T>
const canal::math::Vector<T>& IIRBase<T>::get_pole_coeffs() const {
  return pole_poly_coeff;
}

template<class T>
void IIRBase<T>::set_zero_coeffs(const canal::math::Vector<T>&v) {
  zero_poly_coeff = v;
}
    
template<class T>
void IIRBase<T>::set_pole_coeffs(const canal::math::Vector<T>&v) {
  pole_poly_coeff = v;
}


// ---------------------Non member functions---------------------

template<typename T>
canal::math::Vector<T> filt_b_coef(const IIRBase<T>& f) {
  canal::math::Vector<T> v;
  v = f.get_zero_coeffs();
  return v;
}

template<typename T>
canal::math::Vector<T> filt_a_coef(const IIRBase<T>&f) {
  canal::math::Vector<T> v;
  v = f.get_pole_coeffs();
  return v;
}




}
}
