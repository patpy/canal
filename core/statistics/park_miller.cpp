#include "park_miller.hpp"
constexpr long a = 16807;
constexpr long m = 2147483647;
constexpr long q = 127773;
constexpr long r = 2836;

namespace canal{
namespace stats{
template<class T>
ParkMiller<T>::ParkMiller(long seed_) : seed(seed_)
{
  if(seed == 0)
    seed = 1;
}


template<class T>
void ParkMiller<T>::set_seed(long seed_)
{
  seed = seed_;
  if(seed == 0)
    seed = 1;
}


template<class T>
unsigned long ParkMiller<T>::max()
{
  return m-1;
}

template<class T>
unsigned long ParkMiller<T>::min()
{
  return 1;
}


template<class T>
long ParkMiller<T>::get_one_random_integer()
{
  long k;
  k = seed/q;
  seed = a*(seed-k*q)-r*k;
  if(seed < 0)
    seed += m;
  return seed;
}


template<class T>
RandomParkMiller<T>::RandomParkMiller(const unsigned long dimension_, unsigned long seed_) : Random<T>(dimension_), inner_generator(seed_), initial_seed(seed_)
{
  reciprocal = 1/(1.0+inner_generator.max());
}

template<class T>
Random<T>* RandomParkMiller<T>::clone() const
{
  return new RandomParkMiller<T>(*this);
}

template<class T>
void RandomParkMiller<T>::get_uniform(canal::math::Vector<T>& u)
{
  for (unsigned long i = 0; i < Random<T>::get_dimension(); i++) {
    u.set_val(i, inner_generator.get_one_random_integer()*reciprocal);
  }
}

template<class T>
void RandomParkMiller<T>::skip(const unsigned long n_paths)
{
  canal::math::Vector<T> tmp(Random<T>::get_dimension());
  for (unsigned long i = 0; i < n_paths; i++) {
    get_uniform(tmp);
  }

}


template<class T>
void RandomParkMiller<T>::set_seed(const unsigned long seed_)
{
  initial_seed = seed_;
  inner_generator.set_seed(seed_);
}



template<class T>
void RandomParkMiller<T>::reset()
{
  inner_generator.set_seed(initial_seed);
}



template<class T>
void RandomParkMiller<T>::reset_dimension(const unsigned long new_dimension)
{
  RandomParkMiller<T>::reset_dimension(new_dimension);
  inner_generator.set_seed(initial_seed);
}

      
}//End namespace
}//End namespace
