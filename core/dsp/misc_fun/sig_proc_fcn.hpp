/**
 *@file sig_proc_fcn.hpp
 *
 *@brief This is a library of useful sign processing
 *
 *
 *@author Patrick Kasi
 *
 *@bug No known bug
 */

# ifndef _SIG_PROC_FCN_H
#define _SIG_PROC_FCN_H

// Use to cmath constants such as M_PI
# define _USE_MATH_DEFINES

#include <tuple>
#include <cmath>
#include "core/math/math_vector.hpp"
#include "core/math/complex.hpp"
#include "core/math/math_fcn.hpp"
#include "freqz_dat.hpp"

namespace canal {
namespace dsp {


/**
 *@brief One dimension filter function
 *
 *@detail The filter function is implemented as the transposed direct-form II transposed
 *
 *
 *@tparam b a Vector<T> of polynomial coefficients of poles of filter
 *@tparam a a Vector<T> of polynomial coefficients of zeros of filter
 *@tparam x a Vector<T> containing data to be filtered
 *@return y a Vector<T> containing filtered data
 *
 */
template<typename T>
canal::math::Vector<T> filter(const canal::math::Vector<T>&,
                                   const canal::math::Vector<T>&,
                                   const canal::math::Vector<T>&);


/**
 *@brief Frequency response of a discrete transfer function (filter z-transform)
 *
 *@detail Returns the N-point frequency
 *	
 *  Given numerator and denominator coefficients in vectors B and A. The
 *  frequency response is evaluated at N points equally spaced around the
 * upper half of the unit circle. If N isn't specified, it defaults to 512.
 * filter uses N points around the whole unit circle.
 * filter returns the frequency response at frequencies 
 * designated in radians (normally between 0 and pi).
 *
 *@also filter
 *
 *@author P.K. Kasi
 *
 *@copyright (c) 2019-2020 by Patrick K Kasi
 *@revision 1
 *@date May 2020.
 *
 *@tparam b Vector<T> containing polynomials ('b' coefficients or zeros)
 *@tparam a Vector<T> containing plynomials ('a' coefficients or poles)
 *@tparam fs the sampling frequency (default setting is 1Hz)
 *@param  n the length/number of frequencies points (default setting is 8192)
 *
 *@return  frz_data A data structure containing a vector of physical frequencies of type T and a vector of frequency
 * responses of type complex of T of filter b/a: \n
 *
 *@warning Throws if the size vector inputs 'b' and 'a' are not the same 
 *
 * 
 */

template<typename T>
FreqzData<T>
freqz(const canal::math::Vector<T>&b,
          const canal::math::Vector<T>&a, const T&fs = 1, const int n = 8192);


/**
 *@brief Computes angle
 *
 *tparam c a canal::math::complex<T> object
 *
 *@return theta 
 */
template<typename T>
const T angle(const canal::math::Complex<T>&);


/**
 *@brief Computes angles
 *
 *tparam c a math::Vector<canal::math::Complex<T>> - Vector object of Complex objects of type T
 *
 *@return vec_theta a canal::math::Vector object containing angles of type T
 */
template<typename T>
const canal::math::Vector<T> angle(const canal::math::Vector<
                              canal::math::Complex<T>>&);
    



}

}
// End Namespace

 #include "sig_proc_fcn.cpp"
#endif
