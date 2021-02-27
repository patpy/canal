#include "stats_fcn.hpp"

namespace canal{
namespace stats
{

template<typename T>
T Mean(const canal::math::Vector<T>& v)
{
  unsigned long n = v.get_dimension();
  T sum=0;
  for(unsigned long i = 0; i < n; i++)
    sum += v[i];
  sum /= n;
  return sum;
}


template<typename T>
T Var(const canal::math::Vector<T>& v)
{
  unsigned long n = v.get_dimension();
  T sum_sq=0, sum = 0, s_sq;
  for(unsigned long i = 0; i < n; i++)
  {
    sum_sq += (v[i] * v[i]);
    sum += v[i];
  }

  s_sq = sum_sq - ( (sum*sum)/n );
  s_sq /= n-1;
  return s_sq;
  
}


}//End namespace
}// End namespace
