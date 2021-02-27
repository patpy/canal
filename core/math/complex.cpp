#include "complex.hpp"

namespace canal{
namespace math {
template<class T>
Complex<T>::Complex(const T& r, const T& i) : real(r), imaginary(i)
{
}//constructor

template<class T>
Complex<T>::Complex(const Complex<T>& c) : real(c.real), imaginary(c.imaginary)
{
}//copy constructor

template<class T>
Complex<T>::~Complex()
{
}

template<class T>
const Complex<T>& Complex<T>::operator=(const Complex<T>& c)
{
  if(this != &c)
  {
    real = c.real;
    imaginary = c.imaginary;
  }
  return *this;
}

template<class T>
T Complex<T>:: re()const
{
  return real;
}

template<class T>
T Complex<T>::im()const
{
  return imaginary;
}

template<class T>
void Complex<T>::set_re(const T&r)
{
  real = r;
}

template<class T>
void Complex<T>::set_im(const T&i)
{
  imaginary = i;
}

template<class T>
const Complex<T>& Complex<T>::operator+=(const Complex<T>& c)
{
  real += c.real;
  imaginary += c.imaginary;
  return *this;
}


template<class T>
const Complex<T>& Complex<T>::operator-=(const Complex<T>& c)
{
  real -= c.real;
  imaginary -= c.imaginary;
  return *this;
}

template<class T>
const Complex<T>& Complex<T>::operator*=(const Complex<T>& c)
{
  T real_ = real;
  real = real*c.real + T(-1)*(imaginary*c.imaginary);
  imaginary = real_ *c.imaginary + c.real*imaginary;
  return *this;
}


template<class T>
const Complex<T>& Complex<T>::operator/=(const T& d)
{
  real /= d;
  imaginary /=d;
  return *this;
}


template<class T>
const Complex<T>& Complex<T>::operator*=(const T& d)
{
  real *= d;
  imaginary *=d;
  return *this;
}


template<class T>
const Complex<T>& Complex<T>::operator/=(const Complex<T>& c)
{
  return *this *= (!c)/=abs2(c);
}//divide current complex by a complex

/*
template<class T>
std::ostream& operator << (std::ostream &out, const Complex<T> &c)
{
  out << c.real;
  if(c.imaginary >= 0)
  {
    out << "+i" << c.imaginary <<"\n";
  }
  else
  {
    out << "-i" << std::abs(c.imaginary);
  }

  return out;
}
*/
/*
template<class T>
std::istream& operator >> (std::istream &in, const Complex<T> &c)
{
  std::cout << "Enter Real Part ";
  in >> c.real;
  std::cout << "Enter Imaginary Part ";
  in >> c.imaginary;
  return in;
}
*/
//Ordinary functions

template<class T>
const Complex<T> operator-(const Complex<T>& c)
{
  return Complex<T>( -c.re(), -c.im() );
}//Negative of complex number


template<class T>
const Complex<T> operator-(const Complex<T>& c, const Complex<T>&d)
{
  return Complex<T>(c) -= d;//( c.re()-d.re(), c.im()-d.im() );
}//subtract two complex numbers


template<class T>
const Complex<T> operator+(const Complex<T>&c, const Complex<T>&d)
{
  return Complex<T>(c)+=d;
}

template<class T>
const Complex<T> operator*(const Complex<T>&c, const Complex<T>&d)
{
  return Complex<T>(c) *= d;
}

template<class T>
const Complex<T> operator/(const Complex<T>&c, const Complex<T>&d)
{
  return Complex<T>(c) /= d;
}


template<class T>
const Complex<T> operator+(const Complex<T>&c)
{
  return Complex<T>(c.re(), -c.im());
}


template<class T>
void DispComplex(const Complex<T>& c)
{
  if( c.im() >=0 )
  {
    std::cout<<c.re() <<"+" << c.im() << "i" <<"\n";
  }
  else {
    std::cout<<c.re() << c.im() <<"i"<<"\n";
  }
}

template<class T>
const Complex<T> operator/(const Complex<T>& c, const T& r)
{
  return Complex<T>(c)/=r;
}


template<typename T>
T abs(const Complex<T>&c) {
  return std::sqrt(c.re()*c.re() + c.im()*c.im());
} 

}
}//End Name Space
