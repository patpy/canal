
/**
 *@file normals.hpp
 *
 *@brief This file provides prototypes for a complex class object
 *
 *
 *@author Patrick Kasi
 *@bug No known bug
 */

#ifndef NORMALS_H
#define NORMALS_H
namespace canal{
namespace stats{


template<class T>
T NormalDensity(const T&x);


template<class T>
T CumulativeNormal(const T&x);

template<class T>
T InverseCumulativeNormal(const T& u);
}//end namespace
}//end namespace
 #include "normals.cpp"
#endif
