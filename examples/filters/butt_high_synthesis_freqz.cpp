
#include <iostream>
#include <vector>
#include<string>
#include <matplotlibcpp.h>
#include <canal.hpp>

namespace plt = matplotlibcpp;

/*
  This piece of code uses the vector and dsp modules of the canal library to test
  high pass Butterwork filter synthesis:
  For three orders, filter coefficients are generated, and the frequency responses of the synthesized
  filters are plotted using the c++ matplotlib library
*/

int main() {
  std::cout<< "Frequency Response of a Butterworth High Pass Filter" << "\n";
  
  std::string colors[] = {"b", "g", "r", "c"};
  int order[] = {2, 3, 5, 7}, n = 4, nn = 512;

  // cutt-off
  double fc = 40;

  // sampling
  double fs = 100;
  canal::math::Vector<double> a(3), b(3), f(nn);
  canal::math::Vector<canal::math::Complex<double>> h(nn);
  std::vector<double> xx(nn), yy(nn);
  canal::dsp::FreqzData<double> fqz_data;

  
  for (int i = 0; i < n; i++) {
    
    //canal::dsp::ButterHighPass<double> bhpf(order[i], fc, fs);
    canal::dsp::ButterHighPass<double> bhpf(order[i], fc, fs);
    bhpf.design();
  
    a = canal::dsp::filt_a_coef(bhpf);
    b = canal::dsp::filt_b_coef(bhpf);   

    // print coeffients:
    std::cout<< "a coef:=========== " << "\n";
    std::cout<<a<<"\n";
    std::cout << "b coef:=========== " <<"\n";
    std::cout << b << "\n";
    std::cout<< "============================== " << "\n";
    // call freqz
    fqz_data = canal::dsp::freqz(b, a, fs, nn);

    // Now plot impulse response
    
    for (int j = 0; j < nn; j++) {
      yy[j] = 20*std::log10(canal::math::abs(fqz_data.freq_response[j]));
      xx[j] = fqz_data.freq[j];
      
    }

     plt::plot(xx, yy, colors[i]);
     //plt::text(5*order[i]+4, -39, "N=");
  }

  
  plt::ylabel("Power (dB)");
  plt::xlabel("Frequency (Hz)");
  plt::grid("True");
  plt::xlim(0,50);
  plt::ylim(-100, 5);
  plt::save("./freq_response.png");
  plt::show();
  
   
  
  return 0;
}

// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ -I /home/patrick/COMP167/CANAL/pyplotcpp/ -I /usr/include/python2.7 butt_high_synthesis_freqz.cpp -o bhpf -lpython2.7

