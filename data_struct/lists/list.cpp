//list.cpp
#include "list.hpp"

namespace canal{
namespace dst{
/*
template<class T>
list<T>::list(int n): item(n ? new T*[n] : 0), number(n)			   
{
}//constructor
*/
template<class T>
List<T>::List(int n, const T&t):item(n ? new T*[n] : 0), number(n)
{
  for(int i=0; i< n; i++)
    item[i] = new T(t);
}//constructor with argument of type T

template<class T>
List<T>::List(const List<T>& l): item(l.number ? new T*[l.number] : 0), number(l.number)
{
  for (int i = 0; i < l.number; ++i) {
    if(l.item[i])
      item[i] = new T(*l.item[i]);
    else
      item[i] = 0;
  }
}//copy constructor

template<class T>
List<T>::~List()
{
  for (int i = 0; i < number; ++i) {
    delete item[i];
  }
  delete [] item;
}

template<class T>
const List<T>& List<T>::operator=(const List<T>& l)
{
  if(this != &l)
    {
      if(number != l.number){
	delete [] item;
	 item = new T*[l.number];
      }
      
      for (int i = 0; i < l.number; ++i) {
	if(l.item[i])
        {
	  item[i] = new T(*l.item[i]);
        }
	else {
	  item[i] = 0;
	}
      }
      number = l.number;

    }
  return *this;
}//assignment operator

template<class T>
int List<T>::size()const
{
  return number;	
}

template<class T>
T& List<T>::operator()(int i)
{
 throw_assert(i < number || i >= 0, "Index is out of range");
 return *(item[i]);
}

template<class T>
const T& List<T>::operator[](int i)const
{
 throw_assert(i < number || i >= 0, "Index is out of range");
 //if(item[i])
 return *(item[i]);
}

template<class T>
void List<T>::set(const int i, const T& t)
{
 throw_assert(i < number || i >= 0, "Index is out of range");
 item[i] = new T(t);
}

// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction ()
{
    List<int> TempObj;
}

}//End Namespace
}// End namespace
