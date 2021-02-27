
// math_vector.cpp
#include "math_vector.hpp"
namespace canal {

namespace math {

template<class T>
Vector<T>::Vector(const int  n, const T&t):element(n ? new T[n] : 0), num_rows(n) {
 for (int  i = 0; i < n; i++)
      element[i] = t;
}

template<class T>
Vector<T>::Vector(const int  m, const int  n, const T&a)
    :element(m ? new T[m] : 0), num_rows(m) {
  for (int  j = 0; j < m; j++)
     element[j] = 0;
  element[n] = a;
}


template<class T>
Vector<T>::Vector(std::string c, const T&s,
                          const T&e, const int n)
    :element(n ? new T[n] : 0), num_rows(n) {

  if (c.compare("linspace") == 0) {
    T dt = ((e-s)+1)/n;
    element[0] = s;
    for (int i= 1; i < n; i++)
      element[i] = element[i-1] + dt;
  }
  
}



template<class T>
Vector<T>::Vector(const Vector<T>&v):
    element(v.num_rows ? new T[v.num_rows] : 0), num_rows(v.num_rows) {
  
  for (int  i = 0; i < v.num_rows; i++)
    element[i] = v.element[i];
}
// copy constructor

template<class T>
Vector<T>::~Vector() {
  delete [] element;
}

/*
template<class T>
const T Vector<T>::abs(T& v) {
    return v > 0 ? v : -v;
}
*/

template<class T>
const Vector<T>&
Vector<T>::operator=(const Vector<T>&v) {
  if ( this != &v ) {
    if (num_rows != v.num_rows) {
      delete [] element;
      element = new T[v.num_rows];
      num_rows = v.num_rows;
      }
      
     
     for (int  i = 0; i < v.num_rows; i++) {
       element[i] = v.element[i];
       }
      
    }
  return *this;
}

template<class T>
const Vector<T>& Vector<T>::operator=(const T&a) {
  for (int  i = 0; i < num_rows; i ++)
    element[i] = a;
  return *this;
}
// assignment operator with scalar argument



template<class T>
const Vector<T>&
Vector<T>::operator+=(const Vector<T>& v) {
  throw_assert(num_rows == v.num_rows, "Vectors are not of same dimension");
  for (int  i = 0; i < v.get_dimension(); i++)
    element[i] += v.element[i];
  return *this;
}

template<class T>
const Vector<T>&
Vector<T>::operator-=(const Vector<T>& v) {
  throw_assert(num_rows == v.num_rows, "Vectors are not of same dimensions");
  for (int  i = 0; i < num_rows; i++)
    element[i] -= v.element[i];
  return *this;
}

template<class T>
const Vector<T>&
Vector<T>::operator+=(const T& t) {
  for (int  i = 0; i < num_rows; i++)
    element[i] += t;
  return *this;
}


template<class T>
const Vector<T>&
Vector<T>::operator-=(const T& t) {
  for (int  i = 0; i < num_rows; i++)
    element[i] -= t;
  return *this;
}


template<class T>
const Vector<T>&
Vector<T>::operator*=(const T& t) {
  for (int  i = 0; i < num_rows; i++)
    element[i] *= t;
  return *this;
}

template<class T>
const Vector<T>&
Vector<T>::operator/=(const T& t) {
  for (int  i = 0; i < num_rows; i++)
    element[i] /= t;
  return *this;
}


template<class T>
const T& Vector<T>::get_vec_val(int  i)const {
  return element[i];
}


template<class T>
const T& Vector<T>::operator[](int  i) const {
  return element[i];
}
// read ith component


template<class T>
const Vector<T> Vector<T>::operator[](const Vector<int >& v) const {

  int  n = v.get_dimension();
  Vector<T> w(n), x(*this);
   
  for ( int  i = 0; i < n; i++)
    w.set_val(i, x[v[i]]);
   
  return w;
  
}



template<class T>
const Vector<T>& Vector<T>::operator !=(const Vector<T>& d) {
  
  Vector<T> tmp(*this), tmp2(num_rows);
  int  n = num_rows - d.num_rows, ctr = 0;
  for (int  h = 0; h < d.num_rows; h++) {
    for (int  i = h; i < num_rows; i++) {
        if ( i == d.element[h])
          tmp2.element[i] = 1;
    }
    
  }
  
  delete []element;
  element = new T[n];
  for (int  i = 0; i < num_rows; i++) {
    if (tmp2.element[i] == 0) {
     element[ctr] = tmp.element[i];
     ctr++;
     
    }
    
  }
  
  num_rows = n;
  return *this;
}


template<class T>
const Vector<T>& Vector<T>::operator()(const Vector<T>& v) {
  int  n = num_rows + v.get_dimension();
  Vector<T> w(*this);
  delete [] element;
  element = new T[n];
  int  i = 0;
  for (; i < num_rows; i++)
     element[i] = w.element[i];
   	
   
  for (int  j = 0; j < v.get_dimension(); j++, i++)
     element[i] = v.element[j];
  num_rows = n;
  return *this;
 
}

  
   
template<class T>
T& Vector<T>::operator()(int  i) {
 return element[i]; 
}

template<class T>
const int & Vector<T>::get_dimension()const {
    return num_rows;
  }


template<class T>
void Vector<T>::set_val(int  i, const T& t) {
  element[i] = t;
}
// modify i-th element


// ===============================Ordinary functions=====================




template<class T>
const Vector<T> operator-(const Vector<T>&u, const Vector<T>&v) {
  throw_assert(u.get_dimension() == v.get_dimension(),
               "Vectors are not of same dimension");
  return Vector<T>(u) -= v;
}

template<class T>
const Vector<T> operator-(const Vector<T>&v) {
  return Vector<T>(v) *= -1;
}
// Negate vector



  


template<class T>
Vector<T> operator+(const Vector<T>&v, const T& a) {
  return Vector<T>(v) += a;
}

template<class T>
Vector<T> operator-(const Vector<T>&v, const T& a) {
  return Vector<T>(v) -= a;
}



template<class T>
Vector<T> operator*(const Vector<T>&v, const T& a) {
  return Vector<T>(v) *= a;
}

template<class T>
Vector<T> operator*(const T& a, const Vector<T>&v ) {
  return Vector<T>(v) *= a;
}




template<class T>
Vector<T> operator/(const Vector<T>&v, const T& a) {

  return Vector<T>(v) /= a;
 
}

template<class T>
T operator*(const Vector<T>&u, const Vector<T>&v) {
  throw_assert(u.get_dimension() == v.get_dimension(),
               "Vectors are not of same dimension");
  T sum = 0;
  for (int  i = 0; i < u.get_dimension(); i++)
    sum += (+u[i])*v[i];
  return sum;
}
/*
template<class T>
const Vector<T> operator-(const Vector<T>&u, const Vector<T>&v) {
  return Vector<T>(u) -= v;
}
*/
template<class T>
const Vector<T> operator+(const Vector<T>&u, const Vector<T>&v) {
  throw_assert(u.get_dimension() == v.get_dimension(),
               "Vectors are not of same dimension");
  return Vector<T>(u) += v;
}
// adding vectors


template<typename T>
Vector<bool> operator>(const Vector<T>& v, const T& x) {
  Vector<bool>w(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if ( v[i] > x)
      w.set_val(i, 1);
  }
  return w;
}



template<typename T>
Vector<bool> operator<(const Vector<T>& v, const T& x) {
  Vector<bool>w(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] < x)
      w.set_val(i, 1);
  }
  return w;
}


template<typename T>
Vector<bool> operator>=(const Vector<T>& v, const T& x) {
  Vector<bool>w(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] >= x)
      w.set_val(i, 1);
  }
  return w;
}



template<typename T>
Vector<bool> operator<=(const Vector<T>& v, const T& x) {
  Vector<bool>w(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] <= x)
      w.set_val(i, 1);
  }
  return w;
}




template<typename T>
Vector<bool> operator>(const Vector<T>&v, const Vector<T>&w) {
  throw_assert(v.get_dimension() == w.get_dimension(),
               "Vectors are not of same dimension");
  Vector<bool>x(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] > w[i])
      x.set_val(i, 1);
  }
  return x;
}


template<typename T>
Vector<bool> operator<(const Vector<T>&v, const Vector<T>&w) {
  throw_assert(v.get_dimension() == w.get_dimension(),
               "Vectors are not of same dimension");
  Vector<bool>x(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] < w[i])
      x.set_val(i, 1);
  }
  return x;
}



template<typename T>
Vector<bool> operator>=(const Vector<T>&v, const Vector<T>&w) {
  throw_assert(v.get_dimension() == w.get_dimension(),
               "Vectors are not of same dimension");
  Vector<bool>x(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] >= w[i])
      x.set_val(i, 1);
  }
  return x;
}



template<typename T>
Vector<bool> operator<=(const Vector<T>&v, const Vector<T>&w) {
  throw_assert(v.get_dimension() == w.get_dimension(),
               "Vectors are not of same dimension");
  Vector<bool>x(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] <= w[i])
      x.set_val(i, 1);
  }
  return x;
}





template<typename T>
Vector<bool> operator|(const Vector<T>& v, const Vector<T>& w) {
  throw_assert(v.get_dimension() == w.get_dimension(),
               "Vectors are not of same dimension");
  Vector<bool>u(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] | w[i])
      u.set_val(i, 1);
  }
  return u;
}


template<typename T>
Vector<bool> operator&(const Vector<T>& v, const Vector<T>& w) {
  throw_assert(v.get_dimension() == w.get_dimension(),
               "Vectors are not of same dimension");
  Vector<bool>u(v.get_dimension() );
  for (int  i = 0; i < v.get_dimension(); i++) {
    if (v[i] & w[i])
      u.set_val(i, 1);
  }
  return u;
}


template<class T>
T l2norm_sq(const Vector<T>&u) {
  return u*u;
}

template<class T>
const T l2norm(const Vector<T>&u) {
  return std::sqrt(u*u);
}


template<typename T>
void disp_vec(const Vector<T>& v) {
  for (int  i = 0; i < v.get_dimension(); i++) {
    std::cout<< v.get_vec_val(i)<< "\n";
    }
}


template<typename T>
Vector<T> prune_vec(const Vector<T>& u, const Vector<T>& v) {
  return Vector<T>(u) != v;
}




template<typename T>
Vector<T> perm(const Vector<int >&u,
                        const Vector<T>&v) {
  throw_assert(u.get_dimension() == v.get_dimension(),
               "Vectors are not of same dimension");
  Vector<T> w(v.get_dimension());
  for (int  i = 0; i < v.get_dimension(); i++) {
    int  j = u[i];
    T dat = v[j];
    
    w.set_val(i, dat);
  }
  return w;
}



template<typename T>
const Vector<T> slice(const Vector<T>&u, const canal::Lseq&x) {



  int col_start = x.start_idx;
  int col_end = x.end_idx;
  int col_incr = x.incr;
  
  if (col_end < col_start) {
     std::cout <<"Error: end inde is lower than start index" <<"\n";
     return 0;
   }

  if ( col_end >= u.get_dimension() || col_start < 0)  {
     std::cout<< "Error: indices out of bounds" <<"\n";
     return 0;
  }

  int n_cols = (col_end - col_start) + 1;   
  Vector<T> v(n_cols, 0);
  int ctr = 0;
  for (int i = col_start; i < col_end+1; i+=col_incr) {
    v.set_val(ctr, u[i]);
    ctr++;
  }
  
   
  return v;
}

/*
template<typename T>
Vector<T> operator-(const Vector<T>&u, const T&val) {
  return Vector<T>(u) -= val;
  
}
*/


/*
template<typename T>
Vector<T> operator+(const Vector<T>&u, const T&val) {
  return Vector<T>(u) += val;
  
}
*/

template<typename T>
Vector<T> operator-(const T&val, const Vector<T>&u) {
  return val+(-Vector<T>(u));
   
}

template<typename T>
Vector<T> operator+(const T&val, const Vector<T>&u) {
  return Vector<T>(u) += val;
  
}



/*
template<typename T>
Vector<T> operator/(const Vector<T>&u, const T&val) {
  return Vector<T>(u) /= val;
  
}
*/

/*
template<typename T>
Vector<T> operator*(const Vector<T>&u, const T&val) {
  return Vector<T>(u) *= val;
  
}
*/


template<typename T>
Vector<T> operator/(const T&val, const Vector<T>&u) {
  Vector<T> v(u.get_dimension());
  for (int  i = 0; i < u.get_dimension(); i++)
    v.set_val(i, val/u[i]);
  
  return v;
}



/*
template<typename T>
Vector<T> operator*(const T&val, const Vector<T>&u) {
  return Vector<T>(u) *= val;
  
}
*/


template<typename T>
const Vector<T> elem_mult(const Vector<T>&u,
                                  const Vector<T>&v) {
  throw_assert(u.get_dimension() == v.get_dimension(),
               "Vectors are not of same dimension");
  Vector<T>w(u.get_dimension());
  for (int  i = 0; i < u.get_dimension(); i++)
    w.set_val(i, u[i]*v[i]);
  
  return w;
  
}
// Pointwise vector multiplication


template<typename T>
const Vector<T> elem_div(const Vector<T>&u, const Vector<T>&v) {
  throw_assert(u.get_dimension() == v.get_dimension(),
               "Vectors are not of same dimension");
  Vector<T>w(u.get_dimension());
  for (int  i = 0; i < u.get_dimension(); i++)
    w.set_val(i, u[i]/v[i]);
  
  return w;
  
}
// Pointwise vector dividion



template<typename T>
const Vector<T> concat_vec(const Vector<T>&u,
                                   const Vector<T>&v) {
  return Vector<T>(u)(v);
}


template<typename T>
const Vector<int > find(const Vector<bool>& b) {
  int  ctr = 0, ctr2 = 0;
  for (int  i = 0; i < b.get_dimension(); i++) {
    if (b[i])
       ctr++;
  }

  Vector<int > w(ctr);
  for (int  i = 0; i < b.get_dimension(); i++) {
    if (b[i]) {
      w.set_val(ctr2, i);
      ctr2++;
    }
  }

  return w;
}


template<typename T>
const T min(const Vector<T>&v) {
  T a = v[0];
  for (int  i = 1; i < v.get_dimension(); i++) {
    if (v[i] < a)
     a = v[i];
  }
  return a;
}

template<typename T>
const T max(const Vector<T>&v) {
  T a = v[0];
  for (int  i = 1; i < v.get_dimension(); i++) {
    if (v[i] > a)
     a = v[i];
  }

  return a;
}


template<typename T>
const Vector<T> diff(const Vector<T>&v, const std::string s) {
  int n = v.dimension() - 1;
  Vector<T> w(n);

  if (s.compare("f") == 0) {
    
    for (int  i = 0; i < n; i++)
      w.set_val(i, (v[i+1] - v[i]));
  } else if (s.compare("b") == 1) {
    for (int  i = 0; i < n; i++)
      w.set_val(i, (v[i] - v[i+1]));
  }
  
  return w;
}


template<typename T>
  const Vector<T> abs_vec(const Vector<T>& v) {
    Vector<T> w(v);
    T a;
    for (int  i = 0; i < v.get_dimension(); i++) {
      a = v[i];
      w.set_val(i, a);
    }
    return w;
  }


template<typename T>
const T sum(const Vector<T>&v) {
  T sum_ = 0;

  for (int  i = 0; i < v.get_dimension(); i++)
    sum_ += v[i];
  
  return sum_;
}


}

}//End Namespace
