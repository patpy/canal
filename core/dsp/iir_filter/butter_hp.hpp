/**
 *@file butter_hp.hpp 
 *
 *\author Patrick Kasi
 *
 * \version 1.0 $Revision: 1.0 $
 *
 * \date 2020/04/20
 *
 * Contact: pkasi@yahoo.com
 *
 *@include iir_base.hpp 
 *
 * 
 *
 */



# ifndef BUTTER_HIGHPASS_H
# define BUTTER_HIGHPASS_H


#include "iir_base.hpp"

namespace canal {
namespace dsp {

template<class T> class ButterHighPass : public IIRBase<T>{
 public:

  /**
   *@brief Constructor function that take filter order
   *
   *@param n Filter order
   */
ButterHighPass(int);

  /**
   *@brief Constructor that takes filter order, cut-off frequency and sampling frequency
   *
   *@param n Filter order
   *
   *@tparam fc Cut-off frequency
   *
   *@tparam fs Sampling frequency
   */
ButterHighPass(int, const T&, const T&);
virtual IIRBase<T>* clone() const;

virtual ~ButterHighPass() {
    }


  /**
   *@brief Member function that displays filter coeffcients at the console.
   *
   */
void print();

  /**
   *@brief Member function that derives Butterworth high pass filter coefficients.
   * 
   *
   */
void design() override;
};



} // End dsp namespace
} // End canal namespace

 #include "butter_hp.cpp"
#endif
