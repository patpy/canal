#include <matplotlibcpp.h>
#include <iostream>
#include <vector>
#include <canal.hpp>
 


namespace plt = matplotlibcpp;

int main(int argc, char *argv[])
{


  // In this example, we generate a vector of Gaussian random variables centered at zero using the Computation and Analysis Library (CANAL)
  // Using matplotlibcpp library, we plot the data. Next the random data set is modfied to create a non-stationary time series data set
  // Finally a 1-D Kalman filter is implmented and is used to etimate the mean of the non stationary time series data set (a pot to show the
  // resutls is generated. When the code runs, it will display a plot of Gaussian random data pdf; once the operator closes this plot,
  // another plot showing results of the Kalman filter pops up.
  
  int n = 1000;
  
  // vector<double> x(n), y(n), xx(n),yy(n), xpdf(n), pdf(n);
  canal::math::Vector<double> u(n);
  std::vector<double>grv(n), x(n), pdf(n), y(n);
  
  canal::stats::RandomParkMiller<double> rnd(n);
  rnd.get_uniform(u);  
 
  
  // From uniform random varibale, genetate Gaussian random data and put data in standard vector
  for(int i = 0; i < n; i++)
  {   
    grv.at(i) = canal::stats::InverseCumulativeNormal(u[i]);
    pdf.at(i) = canal::stats::NormalDensity(grv[i]);
    x.at(i) = double(i);    
  }

  // Plot Gaussian random variable
  plt::plot(grv, pdf, "b.");
  plt::xlabel("Standard Gaussian Random Variable");
  plt::ylabel("pdf");
  plt::xlim(-5, 5);
  plt::save("./gauss_rnd.png");
  plt::show();

  
  // Implement a 1 D kalman filter. 

    
  // Modify random data vector generated above to obtain non stationary data
  for(int i =0; i<n; i++){
    
    if(i < n/2){
      grv.at(i) = 4 + grv[i];
    }else{
      grv.at(i) = 12 + grv[i];
    }
    
    
  }

  
  // Define Bayseian filter-1D Kalman filter
  double sigma = 0.11, sig=0.1;
  double u0 = 15, ut = 0, sigt=1, rt, et, K;
  y.at(0) = u0;
  
  for(int j=1; j < n; j++)
    {
       rt = sigma + sig;
       et = grv.at(j) - y.at(j-1);
       sigt = rt*sigma/(rt + sigma);
       K = rt/(sigma + rt);
      y.at(j) = y.at(j-1) + K*et;
     
    }
  
  
  // Plot a line whose name will show up as "Non stationary data" in the legend.
  
  // plt::plot(x, grv, "rx");
  plt::named_plot("Non stationary data", x, grv, "rx");
  // Plot a line whose name will show up as "Mean of Non stationary data" in the legend.
  //  plt:: plot(x, y);
  plt::named_plot("Mean of Non staionary data", x, y);
 
  plt::xlabel("Time(Samples)");
  plt::ylabel("Non stationary mean");
  plt::title("1-D Kalman Filter Estimate of Mean of Non-stationary Data");
  plt::legend();

  
  //plt::xlim(-5, 5);
  plt::save("./kalman_est.png");
  plt::show();
  
  return 0;
}

// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ -I /home/patrick/COMP167/CANAL/pyplotcpp/ -I /usr/include/python2.7 kalman_filter_1D.cpp -o kf -lpython2.7
