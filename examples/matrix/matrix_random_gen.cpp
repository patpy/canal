#include <iostream>
#include <cmath>
#include "canal.hpp"

int main(int argc, char *argv[])
{


   // Example using canal library with a random number generator functionality

  int n = 1000;

  canal::math::Matrix<double> m(n,n);
  canal::math::Vector<double> u(n,0.0), g(n);// Initialize vectors with zeros
  canal::stats::RandomParkMiller<double> rnd(n);
  
  for (int h = 0; h < n; h++){
      // get uniform rnd
      rnd.get_uniform(u);

      //  Generate Gaussian numbers from uniform random numbers
      for(int i = 0; i < n; i++) {   
         g.set_val(i, canal::stats::InverseCumulativeNormal(u[i]));
         //pdf.set_val(i, canal::stats::NormalDensity(g[i]));
      }
      m.set_val(h, g);
  }
  
  
  m = m * m;
  //std::cout<<m<<"\n";
  
  return 0;
}


// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ matrix_random_gen.cpp -o m_rng

// with optimizations 
//g++ -W -g -O3 -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ matrix_random_gen.cpp -o m_rng 
