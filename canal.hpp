
// copyright 2020-2021 Patrick K. Kasi
/**
 *@file canal.hpp
 *@mainpage CANAL - COMPUTATION AND NUMERICAL ANALYSIS LIBRARY
 *
 * 
 *
 *@brief This library (still work in progress) is a collection of numerical computing c++ objects. The goal is to have a unified framework where one could do most computational tasks within one environment and interface.\n At the core of this 
 * library is the implementation of a vector (dynamic) as a mathematical object. Next is the matrix object, implemented as a vector of vector(s). At present several fundamental 
 * vector and matrix operations \n have been implemented and examle code demonstrating this functionality is provided along with library code. More linear algebra based operations will 
 * be added in due course. \n\n To date, there is a random number generator (uniform random ,and functionality to convert these using an inverse Gaussian funtion using a ParkMiller approach), Butterworth (high pass, low pass and band pass) filter design objects, \n filter function that takes data and filter coeficients and returns filtered data, frequency response analysis (similar to MATLAB's freqz). Again, code demonstrating how these modules operate is provided.
*\n\n The library will also add machine learning capability soon; by implementing a neural network library and statistical models. \n 
 * Note that in the current implementation, no speed optimizations are considered as the focus right now is on clarity and simplicity of use. \n Later on, optimizations for speed will be worked upon. Anyone interested in making contributions towards such endeavours is welcome.
 *
 *@author Patrick Kasi
 *@bug No known bug
 */

#ifndef _CANAL_H
#define _CANAL_H

// #include <butter_hp.hpp>
// #include <butter_lp.hpp>
// #include <butter_bp.hpp>
// #include <sig_proc_fcn.hpp>

#include "core/math/math_vector.hpp"
#include "core/math/math_fcn.hpp"
#include "core/math/complex.hpp" 
#include "core/dsp/dsp.hpp"
#include "core/statistics/stats.hpp"
#endif
