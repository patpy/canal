#include <iostream>
#include <matrix.hpp>


int main()
{
  //Example routine to demonstrate features of CANAL Matrix, Vector and Complex objects
  canal::math::Matrix<double> m1, m2(2,3,3.), m(2,3,5.);
  canal::math::Vector<double>v1(2,2.0);
  
  //std::cout<<m2<<"\n";
  // Ad two matrices 
  m1 = m + m2;
  
  // Add a vector to a matrix (adds vetor to each column and final output should be 10 for matrix entries)
  m1 = m1 + v1;
  //mtco::disp_matrix(m1);
  std::cout<<m1<<"\n"; 
  
  //Compute eigen values
  canal::math::Matrix<double> a(3,3,0.);
  canal::math::Vector<canal::math::Complex<double> > v(3,0.);
  a.set_val(0, 0, 2.);
  a.set_val(0, 1, 1.);
  a.set_val(0, 2, 1.);
  a.set_val(1, 0, 1.);
  a.set_val(1, 1, 3.);
  a.set_val(1, 2, 1.);
  a.set_val(2, 0, 1.);
  a.set_val(2, 1, 1.);
  a.set_val(2, 2, 4.);
  //Example adopted from Trefethen and Bau page(209)
  //Expected eigenvalues are: 1.3249, 2.4608, 5.2143,  
  v = canal::math::EigenVal(a);
  std::cout<<"Eigen values of matrix a"<<"\n";
  std::cout<< v << "\n";//display vector of eigenvalues
  
  std::cout<<""<<"\n";
  
  std::cout<<"Generate and display 3X5 matrix wiht all values = 2.3"<<"\n";
  canal::math::Matrix<double> ma(3,5,2.3);
  //mtco::disp_matrix(ma);
  std::cout<< ma << "\n";
  std::cout<<""<<"\n";

  std::cout<<"Now display matrix times constant 3"<<"\n";
  ma = ma * 3.;
  std::cout<< ma << "\n";
  std::cout<<""<<"\n";
  std::cout<<"Generate 3X3 and 5X5 diagonal matrices"<<"\n";
  canal::math::Matrix<double> md, mm, mv, mdd;
  md = canal::math::eye(3,2.);
  mdd = canal::math::eye(5,2.);
  std::cout<< md <<"\n";
  std::cout<<""<<"\n";


  
  //test matrix time a vector
  canal::math::Vector<double> v2(2,2.);
  canal::math::Matrix<double> mt(3,2,1.0), msliced;
  std::cout<<"Generate a 3X2-matrix"<<"\n";
  mt.set_val(0, 0,2);
  mt.set_val(0, 1, 3);
  mt.set_val(2,1, 2);
  std::cout<< mt << "\n";
  std::cout<<""<<"\n";
  std::cout<<"Generate a 2-element vector"<<"\n"; 
  std::cout<< v2 <<"\n";
  std::cout<<""<<"\n";

  //mt*=v;
  mv = mt * v2;
  mt = mv;

  std::cout<<"matrix (mt) times a vector (v)"<<"\n";
  std::cout<< mt << "\n";

  std::cout<<""<<"\n";
  std::cout<<"Matrix (md) times matrix (mt)"<<"\n";
  mm = md*mt;
  std::cout<< mm << "\n";
  mm = mv;
  std::cout<< mm << "\n";
  //std::cout<<"Transpose of matrix: " << canal::math::Transpose(mm)<<"\n";

  std::cout<<"Original matrix"<<"\n";
  std::cout<<a<<"\n";
  std::cout<<"Sliced matrix is: "<<"\n";	 
  msliced = canal::math::slice(a, canal::Lseq(1,1), canal::Lseq(1,2));
  std::cout<<msliced<<"\n";
  //
  std::cout<< mdd << "\n";
  mdd.set_val(canal::Lseq(0,2), canal::Lseq(0,1), a);
  std::cout<< "Matrix to transpose is:" <<"\n" << mdd << "\n";
  mdd = mdd.transpose();
  std::cout<<"Tranposed Matrix is: "<<"\n";
  std::cout<< mdd<<"\n";
  return 0;
}

// g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/eigen/ -I /home/patrick/COMP167/CANAL/core/math/ -I /home/patrick/COMP167/CANAL/ main_matrix.cpp -o m
