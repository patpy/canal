
// Copyrights 2020 Patrick Kasi



/**
 *   
 *@file iir_filter.hpp 
 *
 * \ingroup PackageName
 * (Note, this needs exactly one \defgroup somewhere)
 *
 * \brief Abstract IIR filter class
 *
 * This class is an abstract base interface for Infinite Impulse Response (IIR) digital filters.
 * It cannot be instantiated as an object. Concrete child classes implement specific filters. 
 * The goal is that of open closed concept, allowing for addition of new filter types and yet there will no need to modify any existing code.
 *
 * \author $Author: Patrick Kasi$
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2020/03/27 14:16:20 $
 *
 * Contact: pkasi@yahoo.com
 *
 * @include <cmath>
 * @include <ThrowAssert.hpp>
 * @include <math_vector.hpp>
 * @include <complex.hpp>
 * @include math_fcn.hpp>
 *
 *
 */

# ifndef _IIR_BASE_H
# define _IIR_BASE_H

// to use cmath constants e.g M_PI
# define _USE_MATH_DEFINES
#include <cmath>
#include <ThrowAssert.hpp>
#include "core/math/math_vector.hpp"
#include "core/math/complex.hpp"
#include "core/math/math_fcn.hpp"
#include "data_struct/lists/list.hpp"

namespace canal {
namespace dsp {
template<class T> class IIRBase {
 protected:
  int order;
  T cut_off_freq;
  T samp_freq;

  // a coefficients
  canal::math::Vector<T> pole_poly_coeff;
  
  // b coefficients
  canal::math::Vector<T> zero_poly_coeff;

 public:
  /**
   * Constructor that takes a filter order.
   * This construtor sets sampling frequency to 1Hz and cut-off to 0.2 Hz
   *
   * @param order_ An integer to specify filter order
   */
  explicit IIRBase(int);

  /**
   * A constructor that specifies filter order, cut-off frequency and sampling frequency
   *
   * @param order_ an filter order (integer type)
   * @tparam fc the cut-off frequency of the filter
   * @tparam fs the sampling rate
   */
  IIRBase(int, const T&, const T&);

  /**
   * Virtual copy constructor
   */
  virtual IIRBase<T>* clone() const = 0;

  /**
   * Destructor
   */
  virtual ~IIRBase() {
  }

  /**
   * Member function to get the order of the filter
   * @return The order of the filter (integer type)
   */
  const int& get_order() const;

  /**
   * Member function to get vector of 'b' coeffiecients of the IIR filter design object
   * @return a Vector of type T containing 'b' coeficients
   */
  const canal::math::Vector<T>& get_zero_coeffs() const;

  /**
   * Member function to get vector of 'a' coeffiecients of the IIR filter design object
   * @return Vector of type T containing 'a' coefficients 
   */
  const canal::math::Vector<T>& get_pole_coeffs() const;

    /**
   * Member function to set 'b' coeffiecients of the IIR filter design object
   * @tparam csl::Vector<T>
   */
  void set_zero_coeffs(const canal::math::Vector<T>&);

  /**
   * Member function to set 'a' coeffiecients of the IIR filter design object
   * @tparam csl::Vector<T>
   */
  void set_pole_coeffs(const canal::math::Vector<T>&);

  /**
   * Member function to get the cut-off frequency of object
   * @return the cut-off frequency of the filter object 
   */
  const T get_cutoff_freq() const;

  
  /**
   * Member function to get the sampling frequency of the IIR filter design object
   * @return Returns the sampling frequency of the current IIR filter object 
   */
  const T get_samp_freq() const;

  
  /**
   * Pure virtual member interface function that is defined else where each IIR implementation
   *
   *@return void
   */
  virtual void design() = 0;
};



/**
 * Ordinary function that take an object (or child object)
 * returns the 'b' coefficients of the filter object
 *
 * @tparam f IIR filter object of type T
 *
 * @return Vector of type T containing 'b' coefficients
 */
template<typename T>
canal::math::Vector<T> filt_b_coef(const IIRBase<T>&);


/**
 * Ordinary function that take an object (or child object):
 * returns the 'a' coefficients of the filter object
 *
 * @tparam  f IIR filter object of type T
 *
 * @return Vector of type T containing 'a' coefficients
 */
template<typename T>
canal::math::Vector<T> filt_a_coef(const IIRBase<T>&);

}
}
 #include "iir_base.cpp"
#endif
