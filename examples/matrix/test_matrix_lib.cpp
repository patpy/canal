#include <iostream>
#include <cmath>
#include "canal.hpp"

int main(int argc, char *argv[])
{
  // Declare a Matrix object and display it on the screen
  canal::math::Matrix<double> m(3,5,2.3);
  std::cout<< "M=" <<"\n" << m << "\n";

  //Scale matrix object and display to show results
  m = m * 3.;
  std::cout<< "M*3=" << "\n" << m << "\n";
  std::cout<< "New M/3=" <<"\n" << m/3.0 << "\n";

  // Create matrix and vector objects
  canal::math::Matrix<double> md, mm, mv;
  canal::math::Vector<double> v(2);

  // Set md to diagonal matrix with 2 at the diagonal
  md = canal::math::eye(3,2.);
  std::cout << md << "\n";
  
  // Initialize vector v to 2 and 1
  v.set_val(0,2.0); v.set_val(1,1.0);
  

  //test matrix time a vector
  /* Generate a 3 by 2 matrix initalized to all ones. Then set
     elements 1,1 to 2; 1,2 to 3; and 3,2 to 2
   */ 
  canal::math::Matrix<double> mt(3,2,1.0);
  mt.set_val(0, 0,2);
  mt.set_val(0, 1, 3);
  mt.set_val(2,1, 2);

  // Now dislay the matrix mt and vector v
  std::cout << mt << "\n";
  std::cout << v << "\n";

  
  // Test matrix times a vector
  mv = mt * v;
  mt = mv;
  std::cout<<"matrix timex a vector"<<"\n";
  std::cout << mv << "\n";

  // Test matrix times matrix
  std::cout<<"Matrix times matrix"<<"\n";
  mm = md*mv;
  std::cout << mm << "\n";
  
  // Get second of matrix md as a vector
  v = md[1];
  std::cout<<"second column of diagonal matrix as a vector object is:"<<"\n";
  std::cout << v<< "\n";
  return 0;
}


// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ test_matrix_lib.cpp -o m_lib
