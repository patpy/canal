
#include "sig_proc_fcn.hpp"
namespace canal {
namespace dsp {


// --------------------------------Filter---------------------------
template<typename T>
canal::math::Vector<T> filter(const canal::math::Vector<T>&bc,
                                   const canal::math::Vector<T>&ac,
                                   const canal::math::Vector<T>&x) {
  int n = ac.get_dimension(), m = x.get_dimension();
  canal::math::Vector<T> z(n), y(m), b, a;
  int dt = 1;
  // Normalize coefficients
  b = bc/ac[0];
  a = ac/ac[0];

  for (int i = 0; i < m; i++) {
    y.set_val(i, b[0]*x[i] + z[0]);
    for (int j = 1; j < n; j++) {
      z.set_val(j-1, b[j]*x[i] + z[j] - a[j] * y[i]);
    }
  }
  z = canal::math::slice(z, canal::Lseq(0,n-1,dt));
  return y;
  
}

/*
// ----------------Freqz Function--------------------------

template<typename T>
std::tuple<canal::math::Vector<T>,
           canal::math::Vector<canal::math::Complex<T> > >
freqz(const canal::math::Vector<T>&b,
          const canal::math::Vector<T>&a, const T&fs, const int n) {
 
  
  throw_assert(b.get_dimension() == a.get_dimension(),
               "Ploynomial vectors lengths must be the same");

  // set interval dt
  int dt = 1;

  std::tuple<canal::math::Vector<T>, canal::math::Vector<canal::math::Complex<T>> > freqz_data;
             
  canal::math::Complex<T> c(b[0], 0);
  canal::math::Vector<canal::math::Complex<T>> unit_circ(n), h(n, c), v(n);
  canal::math::Vector<T> w("linspace", 0.0, M_PI, n+1), f(n), m(n);
  // Declare poles and zeros
  canal::math::Vector<canal::math::Complex<T>> p(b.get_dimension()),
             z(b.get_dimension());
  
  p = canal::math::roots(a);
  z = canal::math::roots(b);
  
  // ignore last point in w
  w = canal::math::slice(w, canal::Lseq(0,n-1,dt));
  
  // w = canal::math::real2complex();
  f = w / M_PI * fs / T(2);
  // exp(vector of complex of form 0+ix)
  
  unit_circ = canal::math::exp(canal::math::real2complex(m, w));
                                
  // Zeros
  for (int k = 0; k < z.get_dimension(); k++) {
    v = unit_circ - z(k);
    h = canal::math::elem_mult(h, v);
  }

  // Poles
  for (int k = 0; k < p.get_dimension(); k++) {
    v = unit_circ - p(k);
    h = canal::math::elem_div(h, v);
  }
  
  return std::make_tuple(f, h);
    
}

*/


// ----------------Freqz Function2--------------------------

template<typename T>
FreqzData<T>
freqz(const canal::math::Vector<T>&b,
          const canal::math::Vector<T>&a, const T&fs, const int n) {
 
  
  throw_assert(b.get_dimension() == a.get_dimension(),
               "Ploynomial vectors lengths must be the same");

  // set interval dt
  int dt = 1;

  FreqzData<T> freqz_data;
             
  canal::math::Complex<T> c(b[0], 0);
  canal::math::Vector<canal::math::Complex<T>> unit_circ(n), h(n, c), v(n);
  canal::math::Vector<T> w("linspace", 0.0, M_PI, n+1), f(n), m(n);
  // Declare poles and zeros
  canal::math::Vector<canal::math::Complex<T>> p(b.get_dimension()),
             z(b.get_dimension());
  
  p = canal::math::roots(a);
  z = canal::math::roots(b);
  
  // ignore last point in w
  w = canal::math::slice(w, canal::Lseq(0,n-1,dt));
  
  // w = canal::math::real2complex();
  f = w / M_PI * fs / T(2);
  // exp(vector of complex of form 0+ix)
  
  unit_circ = canal::math::exp(canal::math::real2complex(m, w));
                                
  // Zeros
  for (int k = 0; k < z.get_dimension(); k++) {
    v = unit_circ - z(k);
    h = canal::math::elem_mult(h, v);
  }

  // Poles
  for (int k = 0; k < p.get_dimension(); k++) {
    v = unit_circ - p(k);
    h = canal::math::elem_div(h, v);
  }
  
  freqz_data.freq = f;
  freqz_data.freq_response = h;
	
  return freqz_data;
    
}






template<typename T>
const T angle(const canal::math::Complex<T>& c) {
  T theta = 0;
  /* 
  if (c.re() > 0) {
    theta = std::atan(c.im()/c.re());
  } else if (c.re() < 0) {
    theta = std::atan2(c.im(), c.re()) + M_PI;
  }*/
  theta = -std::atan2(c.im(), c.re());
  // * 180 / M_PI;
  return theta;
}



template<typename T>
const canal::math::Vector<T> angle(const canal::math::Vector<
                              canal::math::Complex<T>>&v) {

  canal::math::Vector<T> a_vec(v.get_dimension());
  for (int i = 0; i < v.get_dimension(); i++) {
    a_vec.set(i, angle(v[i]));
  }

  return a_vec;
}



}
}
// End Namespace
