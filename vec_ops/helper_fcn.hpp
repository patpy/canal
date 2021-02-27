
/**
 *
 *@brief This header file contains prototypes for vector and matrix helper functions
 *
 *
 *
 * \bug No known bugs
 *
 * \author Patrick Kasi
 *
 * \version 1.0
 *
 * \date
 *
 * Contact pkasi@yahoo.com
 */


#ifndef _HELPER_FCN_
#define _HELPER_FCN_

#include<math_vector.hpp>

namespace canal{

template<typename T>
const Vector<T> lseq(T first, T last, T delta);

} // End namespace


#include helper_fcn.cpp
#endif
