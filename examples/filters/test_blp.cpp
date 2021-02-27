
#include <iostream>
#include <vector>
#include <matplotlibcpp.h>
#include <canal>

namespace plt = matplotlibcpp;
/*
  ---------------MATLAB IMPLEMENTATION AS GOLD STANDARD---------------
  N = 5           % Filter order
  fc = 10;        % Hz cutoff freq
  fs = 100;       % Hz sample freq
  Results:
  b =    0.0013    0.0064    0.0128    0.0128    0.0064    0.0013
  a =    1.0000   -2.9754    3.8060   -2.5453    0.8811   -0.1254
 */
int main() {
  std::cout<< "Hello Butterworth Low Pass Filter Design" << "\n";
  int n = 5, nn = 95;
  double fc = 10;
  double fs = 100;
  mtco::MathVector<double> b, a, x(nn), y(nn);
  std::vector<double> xx(nn), yy(nn);
  
  dsp_lib::iir_lib::ButterLowPass<double> blpf(n, fc, fs);
  blpf.design();
  
  a = dsp_lib::iir_lib::GetFilter_a_Coeffs(blpf);
  b = dsp_lib::iir_lib::GetFilter_b_Coeffs(blpf);

  std::cout<< "Printing 'b' coefficients" <<"\n";
  mtco::disp_vector(b);
  std::cout<< "\n" << "Printing 'a' coefficients" <<"\n";
  mtco::disp_vector(a);

  // Impulse response of filter
  x.set(0, 1.0);
  y = dspo::Filter(b, a, x);
  
  // Now plot impulse response
  for (int i = 0; i < nn; i++) {
    yy.at(i) = y[i];
    xx.at(i) = (double(i)/fs);
  }

  plt::plot(xx,yy, "b");
  plt::ylabel("Power");
  plt::xlabel("Time (s)");
  plt::grid("True");
  plt::save("./impulse_response.png");
  plt::show(); 
}


// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CompSci/ -I /home/patrick/COMP167/CompSci/dsp/iirFilter/ -I /home/patrick/COMP167/math/ -I /home/patrick/COMP167/math/vector/ -I /home/patrick/COMP167/math/matrix/ -I /home/patrick/COMP167/math/complex/ -I /home/patrick/COMP167/data_struct/lists/ -I /home/patrick/COMP167/CompSci/eigen/ -I /home/patrick/COMP167/signal_processing/general/ -I /home/patrick/COMP167/signal_processing/dft/ -I /home/patrick/COMP167/graphics/pyplotcpp/ -I /usr/include/python2.7/ test_blp.cpp -o lbf -lpython2.7
