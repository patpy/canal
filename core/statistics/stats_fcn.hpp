/**
 *@file stats_fcn.hpp
 *@brief Prototypes for common statistics computations
 *
 *
 *@author Patrick Kasi
 *@bug No known bug
 */

#include "core/math/math_vector.hpp"
#ifndef _STATS_FCN_H
#define _STATS_FCN_H

namespace canal{
namespace stats{

/**
 *@brief function to compute a mean value, of Vector of type T of real numbers
 *
 *@tparams canal::math::Vector<T>
 *@return T
 */
template<typename T>
T Mean(const canal::math::Vector<T>&);

/**
 *@brief Function to compute the variance of Vector of type T of real numbers
 *
 *@tparams canal::math::Vector<T>
 @tparams canal::math::Vector<T>
 @return T
 */
template<typename T>
T Var(const canal::math::Vector<T>&);

}// End namespace
}// End namespace

#include "stats_fcn.cpp"

#endif
