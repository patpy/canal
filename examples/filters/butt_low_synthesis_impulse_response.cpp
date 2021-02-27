
#include <iostream>
#include <vector>
#include <matplotlibcpp.h>
#include <canal.hpp>

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


/*
   This routine tests the Butterworth filter functinality of the canal library. A gold standard implementation of the
   filter described above is done using MATLAB. Coefficients generated using CANAL's low pass buttworth filter synthesis
   are compared to the gold standard. Furthermore, the filter function is invoked to demonstrate the impulse response of the
   designed filter.
*/


int main() {
  
  int n = 5, nn = 95;
  double fc = 10;
  double fs = 100;
  canal::math::Vector<double> b, a, x(nn), y(nn);
  std::vector<double> xx(nn), yy(nn);
  canal::dsp::FreqzData<double> frqz;
  
  canal::dsp::ButterLowPass<double> blpf(n, fc, fs);
  blpf.design(); // synthesize low pass Butterwoth filter
  
  a = canal::dsp::filt_a_coef(blpf);
  b = canal::dsp::filt_b_coef(blpf);

  std::cout<< "Printing 'b' coefficients" <<"\n";
  std::cout<< b << "\n";
  std::cout<< "\n" << "Printing 'a' coefficients" <<"\n";
  std::cout<< a << "\n";
  std::cout<<"==================================="<<"\n";

  // Impulse response of filter
  x.set_val(0, 1.0);
  y = canal::dsp::filter(b, a, x);
  
  // Now plot impulse response
  for (int i = 0; i < nn; i++) {
    yy.at(i) = y[i];
    xx.at(i) = (double(i)/fs)*1000;
  }


  // Now plot impulse response of filter
  plt::plot(xx,yy, "b");
  plt::ylabel("Power");
  plt::xlabel("Time (ms)");
  plt::grid("True");
  plt::title("Butterworth Low Pass Filter Impluse Response");
  plt::xlim(0,400);
  plt::save("./low_butt_impulse_response.png");
  plt::show();

  // Now get frequency response of filter
  frqz = canal::dsp::freqz(b, a, fs, nn);  
  for(int j = 0; j < nn; j++) {
    yy[j] = 20*std::log10( canal::math::abs(frqz.freq_response[j]));
    xx[j] = frqz.freq[j];
  }

  
  // Now plot frequency response
  plt::plot(xx,yy, "b");
  plt::ylabel("Power (dB)");
  plt::xlabel("Frequency (Hz)");
  plt::grid("True");
  plt::xlim(0,50);
  plt::ylim(-80, 5);
  plt::title("Butterworth Low Pass Filter Frequency Response");
  plt::save("./low_butt_frequency_response.png");
  plt::show();



  // Now plot frequency response of filter
}

// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ -I /home/patrick/COMP167/CANAL/pyplotcpp/ -I /usr/include/python2.7 butt_low_synthesis_impulse_response.cpp -o blp -lpython2.7
