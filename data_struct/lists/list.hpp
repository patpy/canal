//list.hpp

#ifndef _LIST_H_
#define _LIST_H_
#include <ThrowAssert.hpp>

namespace canal{
namespace dst{

template<class T> class List{

protected:
  int number;
  T** item;
public:
  List(int n=0):item(n ? new T*[n] : 0), number(n)
  {
  }
  List(int, const T&);
  List(const List<T>&);
  const List<T>& operator=(const List<T>&);
  ~List();
  int size()const;
  T& operator()(int);
  const T& operator[](int i)const;
  void set(const int, const T&);
};

}//Namespace
}// Namespace
 #include "list.cpp"
#endif
