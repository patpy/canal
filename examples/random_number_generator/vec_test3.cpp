// Testing math vector object
#include <iostream>
#include <vector> //needed to pass into matplotlib for plotting
#include <canal.hpp>
#include <matplotlibcpp.h> //External ploting library see Github

namespace plt = matplotlibcpp;


int main(int argc, char *argv[])
{

  // Example using canal library with a random number generator functionality

  int n = 1000;

  canal::math::Vector<double> u(n,0.0);
  canal::stats::RandomParkMiller<double> rnd(n);
  std::vector<double> gauss_rnd(n), y(n);

  rnd.get_uniform(u);

  //  Put data in std vector for input into matplotlib
  for(int i = 0; i < n; i++) {   
    gauss_rnd.at(i) = canal::stats::InverseCumulativeNormal(u[i]);
    y.at(i) = canal::stats::NormalDensity(gauss_rnd[i]);
        
  }
  
  

  
  //  plot Gaussian random variable using matplotlib
  plt::plot(gauss_rnd, y, "b.");
  plt::xlabel("Standard Gaussian RND Variable");
  plt::ylabel("pdf");
  plt::xlim(-5, 5);
  plt::save("./gauss_rnd.png");
  plt::show();
  
  return 0;
}


// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ -I /home/patrick/COMP167/CANAL/pyplotcpp/ -I /usr/include/python2.7 vec_test3.cpp -o v3 -lpython2.7
