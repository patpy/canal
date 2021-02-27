
#include "math_fcn.hpp"

namespace canal {
namespace math {
template<class T>
const T abs(T& v) {
return v > 0 ? v : -v;
}



template<typename T>
const T sign(const T& r) {
  
  T s;
  if ( r == 0 )
    s = T(0);

  if ( r < 0 )
    s = -T(1);

  if ( r > 0 )
    s = T(1);

  return s;

}


/*
template<class T>
const T Abs(Complex<T>&c)
{
  
  T a = std::sqrt( abs2(c) );
  return a;
}
*/





template<class T>
T exp(const T& x) {
  // when x is large in magnitude, exp(x) is approximated by picking
  // some sufficiently large integer m
  // such that x/2^m is sufficiently small in magnitude
  const int k = 10;
  T xx = x;
  int m = 0;

  while (abs(xx) > 0.5) {
     xx /=2.;
     m++;
  }
  
  // in this way if T is a matrix, then sum is initialized to identity matrix
  T sum = T(1.0);
    
  for (int i = k; i > 0; i--) {
    sum *= xx/T(i);
    sum += T(1.);
  }
    
  for (int i = 0; i < m; i++)
    sum *= sum;
    
  return sum;
  
}


template<class T>
const canal::math::Complex<T> exp(const canal::math::Complex<T>&c) {

      // ordinary exponetial value of real component of complex
      T exp_val = exp(c.re());
      canal::math::Complex<T> euler_exp_val(std::cos(c.im()), -std::sin(c.im()));

      euler_exp_val *= exp_val;
      
      return euler_exp_val;
     
}


template<class T>
const canal::math::Vector<canal::math::Complex<T>> exp(
    const canal::math::Vector<canal::math::Complex<T>>&v) {

  canal::math::Vector<canal::math::Complex<T>> cplex_exp(v.get_dimension());
  
  for (int  i = 0; i < v.get_dimension(); i++)
    cplex_exp.set_val(i, exp(v[i]));

  return cplex_exp;
     
}




template<class T>
const T power(const T& x, const int  n) {

  return n > 0 ?
      (n > 1 ?
      (n%2 ? x * power(x * x, n/2)
       :
       power(x * x, n/2))
      :
       x)
      :1;
}
// Compute a power recursively



template<class T>
const canal::math::Vector<T> power(const T& base,
                                        const canal::math::Vector<int >& v) {
  canal::math::Vector<T> w(v.get_dimension());
  for (int  i = 0; i < v.get_dimension(); i++)
    w.set_val(i, power(base, v[i]) );

  return w;
  
}





int  integer_log(int  n) {
  return n > 1 ? integer_log(n/2)+1:0;
}

template<typename T>
const canal::math::Vector< canal::math::Complex<T> > roots(
    const canal::math::Vector<T>&u) {
  
  int n = u.get_dimension() - 1, j = 0;
  canal::math::Matrix<T> c(n, n), m(n, n);
  canal::math::Vector<T>v(u);
  canal::math::Vector<canal::math::Complex<T>> e;

  v = v / (v[0]);
  // make cn = 1
  for (int i = 1; i < n; i++) {
    c.set_val(j, i, 1);
    j++;
  }

  j = 0;
  for (int i = n; i > 0; i--) {
    c.set_val(n-1, j, -v[i]);
    j++;
  }

  // Matrix library relies on EIGEN Matrix library to compute the roots
  e = canal::math::EigenVal(c);

  return e;
  
}



template<typename T>
canal::math::Vector<T> cplex2real(
    const canal::math::Vector<canal::math::Complex<T>>&v) {
  int  n = v.get_dimension();
  canal::math::Vector<T> w(n);
  for (int  i = 0; i < n; i++) {
    w.set_val(i, v[i].re() );
  }

  return w;
}

template<typename T>
const canal::math::Vector<canal::math::Complex<T>> poly(
    const canal::math::Vector<canal::math::Complex<T>>&u) {

  int  n = u.get_dimension();
  canal::math::Complex<T> c(T(1));
  canal::math::Vector<canal::math::Complex<T>> cp_vec(n+1, 0, 0);
  cp_vec.set_val(0, c);
  for (int  j = 0; j < n; j++) {
     canal::math::Vector<canal::math::Complex<T>> vv(j+1);
     for (int  k = 0; k < j+1; k++) {
      vv.set_val(k, cp_vec[k+1]-u[j]*cp_vec[k]);
     }
     for (int  k = 0; k < j+1; k++) {
        cp_vec.set_val(k+1, vv[k]);
     }
  }
  
  return cp_vec;
}



template<typename T>
const canal::math::Vector<T> poly(const canal::math::Vector<T>&u) {
  canal::math::Complex<T>cval;
  int n = u.get_dimension();
  canal::math::Vector<T> p;
  canal::math::Vector<T>v(u), c(n+1);

  c.set_val(0, 1);
  // Expand recursion formula
  for (int i = 0; i < n; i++) {
    canal::math::Vector<T> vv(i+1);
    for (int j = 0; j < i+1; j++) {
      vv.set_val(j, c[j+1]-v[i]*c[j]);
    }

    for (int k = 0; k < i+1; k++) {
      c.set_val(k+1, vv[k]);
    }
  }
 
  return c;
}





template<typename T>
canal::math::Vector<T> sin(const canal::math::Vector<T>& v) {

  int n = v.get_dimension();
  canal::math::Vector<T> sine_vec(n);
 
  for (int i = 0; i < n; i++) {
    
    sine_vec.set_val(i, std::sin(v[i]));
  }

  return sine_vec;
 
}


template<typename T>
canal::math::Vector<T> cos(const canal::math::Vector<T>& v) {
  int n = v.get_dimension();
  canal::math::Vector<T> cos_vec(n);
  
  for (int i = 0; i < n; i++) {
    
    cos_vec.set_val(i, std::cos(v[i]));
  }
  
  return cos_vec;
  
}



template<typename T>
canal::math::Vector<T> sqrt(const canal::math::Vector<T>& v) {
 int n = v.get_dimension();
 canal::math::Vector<T> sqrt_vec(n);
 for (int i = 0; i < n; i++) {
   sqrt_vec.set_val(i, v[i]*=v[i]);
 }
 
 return sqrt_vec;
}

template<typename T>
canal::math::Vector<canal::math::Complex<T>> sqrt(const canal::math::Vector<canal::math::Complex<T>>& v) {
 int n = v.get_dimension();
 canal::math::Vector<canal::math::Complex<T>> sqrt_vec(n);
 for (int i = 0; i < n; i++) {
   sqrt_vec.set_val(i, canal::math::Complex<T>(v[i])*=v[i]);
 }
 
 return sqrt_vec;
}





template<typename T>
canal::math::Vector<canal::math::Complex<T>> real2complex(
    const canal::math::Vector<T>&v, const canal::math::Vector<T>&w) {
    throw_assert(v.get_dimension() == w.get_dimension(), "Vectors are not of same dimension");
 
    int n = v.get_dimension();
    canal::math::Complex<T> c;
    canal::math::Vector<canal::math::Complex<T>> cvec(n);
   
    for (int i = 0; i < n; i++) {
      c.set_re(v[i]);
      c.set_im(w[i]);
      cvec.set_val(i, c);
    }
   
    return cvec;
    
}


 template<typename T>
  const canal::math::Vector<canal::math::Complex<T>> operator/(const canal::math::Vector<canal::math::Complex<T>>cplex_vec, const T& t) {
  
  return canal::math::Vector<canal::math::Complex<T>>(cplex_vec) /= t;

}




}
}
//  End NameSpace








