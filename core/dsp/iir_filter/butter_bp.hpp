
// Copyright @Patrick Kasi May 2020

/**
 *@file butter_bp.hpp
 *
 *\brief Butterworth Bandpass Filter Design
 *
 *This class implements a BUtterworth bandpass filter.
 *
 *The class can be used as follows:
 *
 *    \code{.cpp}
 *    #include <iostream>
 *    #include <dsp.hpp>
 *
 *    int order = 5; // filter order
 *    int n_pts = 100; // number of data points
 *    \endcode
 *
 *@note This method of implementing the filter may be unstable for high order filters
 *
 *@author Patrick Kasi
 *
 *@verion 1.0
 *
 @date 2020/05/25
 *
 *Contact pkasi@yahoo.com
 *
 *@include iir_base.hpp
 */

# ifndef _BUTTERWORTH_BANDPASS_H
# define _BUTTERWORTH_BANDPASS_H

#include "iir_base.hpp"

namespace canal {
namespace dsp {
template<class T> class ButterworthBandPass : public IIRBase<T> {
 public:
  /**
   *@brief Constructor that takes order of Butterworth bandpass filter
   *
   * By default the center freqence is 0.2, and bandwith is 0.05
   *
   *@param order_ integer to specify the order of the filter
   */
  explicit ButterworthBandPass(const int);

  /**
   *@brief Contructor that takes filter order, center frequency(Hz), bandwidth(Hz), and sampling frequency (samples per sec)
   *
   *@param order_ An integer to specify order of the filter
   *@tparam f_center_ the center frequency of the bandpass fileter (Hz)
   *@tparam bandwidth_ the bandwidth of the bandpass filter (Hz)
   */
  ButterworthBandPass(const int, const T&, const T&, const T&);
  virtual IIRBase<T>* clone() const;
  virtual ~ButterworthBandPass() {
  }

  /**
   *\brief Member function that synthtesizes the coeficients of the Butterworth bandpass filter
   */
  void design() override;
  
 private:
  T band_width;
  // T f_center;
};
}
}

 #include "butter_bp.cpp"


#endif

