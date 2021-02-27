/**
 *@file park_miller.hpp
 *
 *@brief This file provides prototypes for a complex class object
 *
 *
 *@author Patrick Kasi
 *@bug No known bug
 */

#ifndef PARK_MILLER_H
#define PARK_MILLER_H

#include "random.hpp"
namespace canal{
namespace stats{
template<class T>
class ParkMiller{
 private:
  long seed;

 public:
  ParkMiller(long seed_ = 1);
  long get_one_random_integer();
  void set_seed(long seed_);

  static unsigned long max();
  static unsigned long min();
};

template<class T>
class RandomParkMiller : public Random<T>
{
 private:
  ParkMiller<T> inner_generator;
  unsigned long initial_seed;
  T reciprocal;

 public:
  RandomParkMiller(const unsigned long dimension_, unsigned long seed_=1);
  virtual Random<T>* clone() const;
  virtual void get_uniform(canal::math::Vector<T>& );
  //virtual void get_integer(MathObjects::Vector<T>&);
  virtual void skip(const unsigned long n_paths);
  virtual void set_seed(const unsigned long seed_);
  virtual void reset();
  virtual void reset_dimension(const unsigned long new_dimension);
};

}//End namespace
} // End namespace 
 #include "park_miller.cpp"
#endif
