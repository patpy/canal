// Copyright



#ifndef FREQZ_H
#define FREQZ_H


#include "core/math/math_vector.hpp"

namespace canal{
namespace dsp{

template<class T> struct FreqzData{

  FreqzData()
  {
  }

  //copy constructor
  FreqzData(const FreqzData<T>&f):freq(f.freq), freq_response(f.freq_response)  {
    
  }

  //Assignment operator where user can write "frz = frz1" to assign frz1 to current object frz 
  const FreqzData<T>& operator=(const FreqzData<T>&f)
  {
    if ( this != &f ) {
      freq = f.freq;
      freq_response = f.freq_response;
    }
    return *this;
  }
  

  virtual ~ FreqzData()
  {
  }

  canal::math::Vector<T> freq; // Phyisical Frequency 
  canal::math::Vector<canal::math::Complex<T>> freq_response; // Frequency response

  
};

}
}

#endif
