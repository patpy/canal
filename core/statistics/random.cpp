#include "random.hpp"

namespace canal{
namespace stats{
template<class T>
void Random<T>::get_gaussian(canal::math::Vector<T>& u)
{
  get_uniform(u);
 for (unsigned long i = 0; i < dimension; i++)
  {
    //T x = u[i];
    u.set_val(i, InverseCumulativeNormal(u[i]) );
  }
  
}


template<class T>
void Random<T>::reset_dimension(unsigned long new_dimension)
{
  dimension = new_dimension;  
}

template<class T>
Random<T>::Random(unsigned long dimension_):dimension(dimension_)
{
}

}//End namespace
}//End namespace
