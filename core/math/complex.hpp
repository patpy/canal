
/**
 *@file complex.hpp
 *
 *@brief This file provides prototypes for a complex class object
 *
 *
 *@author Patrick Kasi
 *@bug No known bug
 */

#include <fstream>
#include <iostream>
#include <cmath>

#ifndef _COMPLEX_H
#define _COMPLEX_H
namespace canal{
namespace math {



template<class T>
class Complex{

 private:
  T real;
  T imaginary;
 public:
  /**
   *@brief Complex type constructor to initalize the complex object
   *@param real part
   *@param imaginary part
   */
  Complex(const T& r=0, const T& i=0);

   /**
   *@brief Complex type copy constructor to initalize the complex object
   *@param Complex object
   *
   */
  Complex(const Complex<T>&);

   /**
   *@brief Destructor to clean up complex object upon exit
   * The default destructor has an empty block because the "real" and "imaginary fields are destroyed implicitly (in this order)
   *
   */
  ~Complex();

  
   /**
   *@brief Assignment Operator
   *Current object is assigned a value from the argument
   *Current object is returned by reference
   *Allows user to write commands like "a=b=c" where a,b, and c are well defined Complex objects
   *@param Complex object
   *@return Complex Object
   */
  const Complex<T>& operator=(const Complex<T>&);
  
   /**
   *@brief Public member function to return real part
   *
   */
  T re() const;
   
   /**
   *@brief Public member function to return imaginary part
   *
   */
  T im() const;
  
  /**
   *@brief Public member function to set a real component of the complex object
   *
   */
  void set_re(const T&);
  
 /**
   *@brief Public member function to set a real component of the complex object
   *
   */
  void set_im(const T&);

  //Arithmetic operators
  /**
   *@brief Plus Assignment Operator
   *With this operator, a user can make the following expression: "a = b+=c" to add 'b' and 'c'
   *where a,b, and c are well defined Complex objects
   *
   *@param Complex<T>
   *@return Complex<T>
   */
  const Complex<T>& operator+=(const Complex<T>&c);

 /**
   *@brief Minus Assignment Operator
   *With this operator, a user can make the following expression: "a = b-=c" to subtract 'b' and 'c'
   *where a,b, and c are well defined Complex objects
   *
   *@param Complex<T>
   *@return Complex<T>
   */
  const Complex<T>& operator-=(const Complex<T>&);

 /**
   *@brief Times Assignment Operator
   *With this operator, a user can make the following expression: "a = b*=c" to multiply 'b' and 'c'
   *where a,b, and c are well defined Complex objects
   *
   *@param Complex<T>
   *@return Complex<T>
   */
  const Complex<T>& operator*=(const Complex<T>&);


   /**
   *@brief Division Assignment Operator
   *With this operator, a user can make the following expression: "a = b/=c" to divide 'b' and 'c'
   *where 'a' and 'b' are well defined Complex objects, and c is a real number
   *
   *@tparam T
   *@return Complex<T>
   */
  const Complex<T>& operator/=(const T&);

  
  /**
   *@brief Division Assignment Operator
   *With this operator, a user can make the following expression: "a = b*=c" to divide 'b' and 'c'
   *where 'a' and 'b' are well defined Complex objects, and c is a real number
   *
   *@tparam T
   *@return Complex<T>
   */
  const Complex<T>& operator*=(const T&);

   /**
   *@brief ! Operator
   *Implemented as a friend function of the class. With this operator, a user can write "!c"
   *to return complex conjugate of complex object 'c'.
   *This function is a friend function for reasons: it does not need the current object; second
   *if it were implemented as as an ordinary function, then member functions would not be able
   *to use it in their implementations
   *
   *@param Complex<T>
   *@return Complex<T>
   */   
  friend Complex<T> operator!(const Complex<T>&c)
  {
    return Complex<T>(c.re(),-c.im());
  }


   /**
   *@brief function abs2 to return absolute values of a complex number
   *
   *
   *@param Complex<T> 
   *@return T The square of the of the absolute value of a complex number
   */
  friend T abs2(const Complex<T>&c)
  {
    return c.re() * c.re() + c.im() * c.im();
  }


   /**
   *@brief Division Assignment Operator
   *With this operator, a complex object is divided by another complex object.
   *where a,b are well defined Complex objects, and c is a real number
   *
   *@param Complex<T>
   *@return Complex<T>
   */
  const Complex<T>& operator/=(const Complex<T>&);

  /**
   *@brief Insertion operator
   */
    friend std::ostream& operator << (std::ostream&out, const Complex<T>&c)
    {
  out << c.real;
  if(c.imaginary >= 0)
  {
    out << "+i" << std::abs(c.imaginary) <<"\n";
  }
  else
  {
    out << "-i" << std::abs(c.imaginary)<<"\n";
  }

  return out;
}


  /**
   *@brief Extraction operator
   */
  //friend std::istream& operator >> (std::istream &, Complex<T>&);
};//End class

/**
   *@brief Minus Operator
   *User can write "-c" to get minus of the complex number 'c'.
   *
   *@param Complex<T>
   *@return Complex<T>
   */
template<class T>
const Complex<T> operator-(const Complex<T>&);



/**
   *@brief Binary Minus Operator
   *Returns the difference between two compex numbers.
   *Operator can write "a - b"
   *
   *@param Complex<T>
   *@param Complex<T>
   *@return Complex<T>
   */
template<class T>
const Complex<T> operator-(const Complex<T>&, const Complex<T>&);



/**
   *@brief Binary Plus Operator
   *Returns the sum of two compex numbers.
   *Operator can write "a + b"
   *
   *@param Complex<T>
   *@param Complex<T>
   *@return Complex<T>
   */
template<class T>
const Complex<T> operator+(const Complex<T>&, const Complex<T>&);



/**
   *@brief Binary Times Operator
   *Returns the product of two compex numbers.
   *Operator can write "a * b"
   *
   *@param Complex<T>
   @param Complex<T>
   *@return Complex<T>
   */
template<class T>
const Complex<T> operator*(const Complex<T>&, const Complex<T>&);



/**
   *@brief Binary Division Operator
   *Returns the division of two compex numbers.
   *Operator can write "a / b"
   *
   *@tparam Complex<T>
   *@tparam Complex<T>
   *@return Complex<T>
   */
template<class T>
const Complex<T> operator/(const Complex<T>&, const Complex<T>&);



/**
   *@brief Binary Division Operator
   *Returns the division of a compex number by a constant.
   *Operator can write "a * b"
   *
   *@tparam Complex<T>
   *@tparam Complex<T>
   *@return Complex<T>
   */
template<class T>
const Complex<T> operator/(const Complex<T>&, const T&);



/**
   *@brief Unary Plus Operator
   *Returns the complex conjugate of a compex number.
   *Operator can write "+v for any numerical type: real or complex
   *
   *t@param Complex<T>
   *@return Complex<T>
   */
template<class T>
const Complex<T> operator+(const Complex<T>&);

/**
 *@brief Function prints compex number on the console
 *
 *@param Complex<T>
 */
template<class T>
void DispComplex(const Complex<T>&);

template<typename T>
T abs(const Complex<T>&);

}
}//End Name Space
 #include "complex.cpp"
#endif
