/**
 *@file math_fcn.hpp
 *
 *@brief This is a library of useful math utilities
 *
 *
 *@author Patrick Kasi
 *
 *@bug No known bug
 */


#include <cmath>
#include "complex.hpp"
#include "math_vector.hpp"
#include "matrix.hpp"

# ifndef _MATH_FCN_H
#define _MATH_FCN_H

namespace canal {
namespace math {


/**
 *@brief absolute value of a numerical type
 *@param v
 @return abs(v)
*/
template<class T>
const T abs(T&);

/**
*@brief Real sign function
*@tparam r a real value of type T
*
*@return s the sign function of input r
*/

template<typename T>
const T sign(const T&);


/**
 *@brief overloading Abs function.
 *@detail This implementation overloads the Abs function so that a user can
 *call the same function to compute the absolute value of a complex number 
 *@tparam MathObjects::Complex<T> v
 @return abs(v)
*/
/*
template<class T>
const T Abs(Complex<T>&);
*/


/**
 *@brief Function computes the power of a number
 *
 *@details This function implements the power function. It is template based, is based 
 *on an efficient algorithm which requires at most 2log_base2(2) multiplications.
 *With this template function, a user can simply write "MathObjects::Power(base, exp)", where base is *real number or a square matrix of real numbers, and exp is an unsigned integer.
 *
 *@tparam T Type of real number, square matrix (with well defined * operator) of real number.
 *
 *@return T The nth power of type. 
 */
template<class T>
const T power(const T&, const unsigned int);



/**
 *@brief Function computes the power of a number
 *
 *@details This function implements the power function. It is template based, is based 
 *on an efficient algorithm which requires at most 2log_base2(2) multiplications.
 *With this template function, a user can simply write "MathObjects::Power(base, exp)", where base is *real number or a square matrix of real numbers, and exp is an unsigned integer.
 *
 *@tparam T Type of real number, square matrix (with well defined * operator) of real number.
 *@tparam MathVecor<unsigned int> A vecotr of powers to some base
 *
 *@return Vector<T> The 0:n-1 th powers of base of type T. 
 */
template<class T>
const canal::math::Vector<T> power(const T&, const canal::math::Vector<unsigned int>&);


/**
 *@brief function to implement exoponential function
 * Computes exponent of a real or a matrix of a reals.
 * The exponent is estimated based on the Taylor series
 *
 *@tparam x where T is a real or a csl::Matrix<T>
 *
 *return The exponential value of type T
 */
template<class T>
T exp(const T&);


/**
 *@brief function to implement exoponential function
 * Computes exponent of a complex number.
 *
 *
 *@tparam c a complex number of type T
 *
 *return The Euler exponential
 *
 *@overloaded
 */
template<class T>
const canal::math::Complex<T> exp(const canal::math::Complex<T>&);


/**
 *@brief function computes Euler exponential 
 *
 *@tparam v A csl::Vector of csl::Complex<T> numbers  
 *
 *
 *@return A Vector Object of Euler exponentials
 *
 *@overloaded
 */
template<class T>
const canal::math::Vector<canal::math::Complex<T>> exp(const canal::math::Vector<canal::math::Complex<T>>&);


/**
 *@brief Function Computes Integer Logarithm 
 *
 *@param unsigned integer
 *@param unsigned integer 
 *
 *@return int the log of some interger to the base of type T.  
 */

unsigned int integer_log(unsigned int);



/**
 *@brief Function to compute roots of a polynomial 
 *
 *
 *@tparam csl::Matrix<csl::Complex<T>> vector of a polynomial coefficients:
 *The coefficients represent increasing degree (coefficient in position zero is the degree 0,
 *coefficient in position 1 is degree 1 etc)
 *
 *@return csl::Vector<csl::Complex<T> > 
 *
 *@return int the log of some interger to the base of type T  
 */
template<typename T>
const canal::math::Vector< canal::math::Complex<T> > roots(const canal::math::Vector<T>&);

/**
 *@brief Function to find coefficients of a polynomial, given roots
 *
 *@tparams const csl::Vector<csl::Complex<T> >
 *@return const csl::Vector<T>
 */
template<typename T>
const canal::math::Vector<canal::math::Complex<T>> poly(const canal::math::Vector<canal::math::Complex<T> >&);



/**
 *@brief Function to find coefficients of a polynomial, given roots
 *
 *@tparams const csl::Vector<T>
 *@return const csl::Vector<T>
 */
template<typename T>
const canal::math::Vector<T> poly(const canal::math::Vector<T>&);


/**
 *@brief Function that inputs a vector of complex objects, and returns a vector of reals
 *
 *
 *@tparams v Vector<canal::math::Complex<T>>
 *@return a vector of reals 
 */
template<typename T>
canal::math::Vector<T> cplex2real(const canal::math::Vector<canal::math::Complex<T>>&);

/**
 *@brief Function takes a vector and returns sin of each vector entry
 *
 *
 *@tparams csl::Vector<T>
 *@return csl::Vector<T>
*/
template<typename T>
canal::math::Vector<T> sin(const canal::math::Vector<T>&);

/**
 *@brief Function takes a vector and returns cosine of each vector entry
 *
 *
 *@tparams csl::Vector<T>
 *@return csl::Vector<T>
*/
template<typename T>
canal::math::Vector<T> cos(const canal::math::Vector<T>&);



/**
 *@brief Function takes a vector and returns elementwise square root of values of a vector
 *
 *
 *@tparams v A canal::math::Vector<T> object containing real numbers
 *@return A vetor, canal::math::Vector<T>, of square root values or complex Type of reals
*/
template<typename T>
canal::math::Vector<T> sqrt(const canal::math::Vector<T>&);



/**
 *@brief Function takes a vector and returns elementwise square root of values of a vector
 *
 *
 *@tparams v A canal::math::Vector<cls::mfl::Complex<T>> object containing real numbers
 *@return A vetor, canal::math::Vector<cls::mfl::Complex<T>>, of square root values or complex Type of reals
 *
 *@overload
*/
template<typename T>
canal::math::Vector<canal::math::Complex<T>> sqrt(const canal::math::Vector<canal::math::Complex<T>>&);

/**
 *@brief Function that takes takes real vectors (a and jb) and returns a vector of complex type
 *
 *
 *@tparams csl::Vector<T>
 *@tparams csl::Vector<T>
 *@return csl::Vector<Complex<T>>
 * 
*/
template<typename T>
canal::math::Vector<canal::math::Complex<T>> real2complex(const canal::math::Vector<T>&,
                                             const canal::math::Vector<T>&);



 /**
   *@brief Division Assignment Operator
   *
   *
   *
   *@tparam cplex_vec
   *@tparam a 
   *@return Complex<T>
   *
   *@overload
   */
  template<typename T>
  const canal::math::Vector<canal::math::Complex<T>> operator/(const canal::math::Vector<canal::math::Complex<T>>, const T&);

}
}
// End Name SPace

 #include "math_fcn.cpp"
#endif
