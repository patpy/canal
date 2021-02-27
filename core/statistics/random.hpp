/**
 *@file random.hpp
 *
 *@brief This file contains prototypes for a random generator class 
 *
 *@author Patrick Kasi
 *@bug No known bug
 */

#ifndef RANDOM_H
#define RANDOM_H

#include "core/math/math_vector.hpp"
#include "normals.hpp"

namespace canal{
namespace stats{
template<class T> class Random{
private:
  unsigned long dimension;
public:
  Random(unsigned long dimension_);
  inline unsigned long get_dimension();

  /**
   *@brief copy constructor as a pure virtual function
   *@details This is implemented in children classes that implement various types of random generators
  */
  virtual Random* clone() const=0;

  /**
  *@brief Member pure virtual function to generate uniform numbers
  *@details Details of the uniform random generator member fuctions are delt with in child classes
  */
  virtual void get_uniform(canal::math::Vector<T>& u)=0;
  //virtual void get_integer(MathObjects::Vector<T>& u) = 0;
  
  virtual void skip(unsigned long n_paths)=0;
  
  virtual void set_seed(unsigned long Seed) = 0;
  
  virtual void reset()=0;

  /**
   *@brief Member function to generate Gaussian random variables
   *@details This member function generates Gaussian random varibales. It dependents on the random generator responsible for tthe uniform random numbers 
   *
   *@tparams canal::math::Vector<T> Vector of uniform random numbers
  */
  virtual void get_gaussian(canal::math::Vector<T>& u);
  
  /**
  *@breif Member function to set the number of random numbers, that will be generated.
  */
  virtual void reset_dimension(unsigned long new_dimension);
};

template<class T>
unsigned long Random<T>::get_dimension()
{
  return dimension;
}

}//end namespace
} // end namespace
 #include "random.cpp"
#endif
