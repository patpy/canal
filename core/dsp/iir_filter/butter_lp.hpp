
// Copyrights Patrick Kasi - April 2020

/**
 *   
 *@file butter_lp.hpp 
 *
 * 
 * @brief Butterworth Low Pass Filter Design filter class
 *
 * This class implements a specific IIR filter: the Butterworth Low Pass Filter.
 *
 * \b References:
 *
 * \cite blinchikoff1976filtering
 *
 * \author Patrick Kasi
 *
 * \version 1.0
 *
 * \date 2020/01/1
 * 
 * Contact: pkasi@yahoo.com
 * 
 *
 */



# ifndef BUTTER_LOWPASS_H
# define BUTTER_LOWPASS_H


#include "iir_base.hpp"

namespace canal {
namespace dsp {
template<class T> class ButterLowPass : public IIRBase<T>{
 public:
ButterLowPass(int);
ButterLowPass(int, const T&, const T&);
virtual IIRBase<T>* clone() const;

virtual ~ButterLowPass() {
    }
void print();

  /**
   * \brief member function to synthesize a Butterworth Low Pass filter
   *
   *
   */
virtual void design() override;
};


/*
 *@brief Ordinary function that takes an IIRBase object and returns a list of cofficients.
 * The first item is a vector that contains the denominator coefficients and the the second
 * vector contains the numerator coefficients.
 *
 *@tparam fobj IIR filter object of type T
 *@return A list of two Mathvectors of of "a" and "b" filter coefficients
 */
/*
template<typename T>
const dst::list<canal::math::MathVector<T>> get_coeff(const IIRBase<T>&);
*/

} 
}
 #include "butter_lp.cpp"
#endif
