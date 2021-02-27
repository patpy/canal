// Testing math vector object
#include <iostream>
#include <canal.hpp>

int main(int argc, char *argv[])
{

  std::cout<<"Example of vector operations"<<"\n";
  
  //Examples of vector functionality
  canal::math::Vector<double> ll(10, 3.0), ll2(10,2.), ll3; 
  
  // Sum vectors
  std::cout<<"Print sum of vectors (ll, and ll2),"; 
  std::cout<<"each containing 10 items: a first vector of 3's and a second vector of 2's"<<"\n";
  std::cout<<"Output should a vector of 10 items, each equaling to 5"<<"\n";

  std::cout<<ll+ll2<<"\n";
  
  // Difference of vectors
  std::cout<<"Print difference of vectors, each containing 10 items:";
  std::cout<<" a first vector of 3's and a second vector of 2's"<<"\n";
  std::cout<<"Output should a vector of 10 items, each eqauling to 1"<<"\n";

  std::cout<< ll-ll2 <<"\n";
  
  // Negating a numerals of a vector
  std::cout<<"Negative of a vector: output should -3's"<<"\n";
  std::cout<<-ll<<"\n";

  // Subtract a constant from a vector
  std::cout<<"Vector minus a constant (2 in this case): output should be 1's"<<"\n";
  std::cout<< ll-2. <<"\n";

  std::cout<<"Vector times constant (3): output should be 9's"<<"\n";
  std::cout<< ll*3. <<"\n";

  std::cout<<"dot product of vectors ll, and ll2"<<"\n";
  std::cout<<ll*ll2<<"\n";
  
  std::cout<<"Now return l2 norm squared of vector ll (vector of 10 3's)"<<"\n";
  std::cout<<canal::math::l2norm_sq(ll)<<"\n";
 
  std::cout<<"Now return l2 norm of vector ll (vector of 10 3's)"<<"\n";
  std::cout<<canal::math::l2norm(ll)<<"\n";
  std::cout<<"Concatenate the two vectors: should now have a vector with twenty items"<<"\n";
  ll3 = canal::math::concat_vec(ll, ll2);
  std::cout<< ll3 << "\n";
  
  return 0;
}

//g++ -W -g -std=c++14 -I /home/patrick/COMP167/CANAL/ -I /home/patrick/COMP167/CANAL/eigen/ vec_test2.cpp -o v

