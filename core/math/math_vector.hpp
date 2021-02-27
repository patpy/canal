
/** @file math_vector.hpp
 *  
 * @brief This contains the prototypes for a dynamic math vector object
 *
 *  
 *  @author Patrick Kasi
 *  @bug No known bugs.
 */

# ifndef _MATH_VECTOR_H_
#define _MATH_VECTOR_H_
#include <cmath>
#include <string>
#include <ThrowAssert.hpp>
#include "vec_ops/lseq.hpp"

namespace canal {
namespace math {
/** @class Class Vector
 * The Vector object implements a vector as a math object.
 *
 */
template<class T>
class Vector{
 protected:
  T* element;
  int  num_rows;
 
 public:
  
 Vector(const int  n = 0, const T&t = 0); 

 /**
   *@brief Constructor that inputs vector length, Type T, and string linspace.
   *@detail This constructor initalizes a vector to values from m to n-1, where m <=n-1. 
   *@param n, an integer to speify vector length, type T to specify vector element
   *and string linspace
   */
/*
  Vector(std::string c, const int  n = 0, const T&t = 0,
             const T& dt = 1):element(n ? new T[n] : 0), num_rows(n) {
    
    if (c.compare("linspace") == 0) {
      element[0] = t;
      for (int  i = 1; i < n; i++)
        element[i] = element[i-1]+dt;
    } else {
     for (int  i = 0; i < n; i++)
        element[i] = t;
    }
  }
*/

  /**
   *@brief Constructor that creates a a vector: currently on creates linearly spaced vector
   *
   *@todo Add functionality so that it is possible to create logarithmically spaced vector etc.
   *
   *@param c A string ('linspace') to specify type of spaced vector
   *@tparam s starting value of the vector
   *@tparam e last value of the vector
   *@param n the dimension of the vector
   *
   *
   */
  Vector(std::string, const T&, const T&, const int );
    

 /**
 * @brief Constructor that takes integer (size of vector), another integer n to construct nth unit vector
 * and value a of type (the nth component's value is a).
 * Example:
 *
 *    \code{.cpp}
 *    // Create a vector with ten elements, and 5th element is 1 and the rest are zeros
 *    Vector<double> unit_vec(10, 5, 1);
      \endcode
 */
  Vector(const int  m, const int  n, const T&a);
             

  /**
   * @brief Copy constructor
   *
   */
  Vector(const Vector<T>&);
 
  virtual ~Vector();

  
  // Operator functions
 /**
 *@brief Assignment operator.
 *@details Assignemnet operator where a user can write command like "u=v" to assign vector 'v' to current object vector 'u'.
 *
 *@tparam Vector<T>
 *@return Vector<T>
 *
 *@overload 
 */
  const Vector<T>& operator=(const Vector<T>&);


  /**
  *@brief Assignment operator
  *@details This is yet another assignemnet operator, that takes a scalar as input. It assigns the scalar to each of elements of the current vector object. A user can write command like "u=a" to assign scalar 'a' to all elements of vector 'u'
  *
  *@tparam Vector<T>
  *@return Vector<T>
  *
  *@overload 
  */
  const Vector<T>& operator=(const T&);
  
   /**
   *@breif += operator
   *@details Thsi operator takes a vector as input for the math vector object. Computes sum of two corresponding elements of input vector and current vector object. User can write command like "u+=v" to sum vectors 'v' and 'u'
   *
   *@tparam Vector<T>
   *@return Vector<T>
   * 
   *@overload 
   */
  const Vector<T>& operator+=(const Vector<T>&);
      
   /**
   *@brief -= operator that takes a vector as input for the math vector object.
   *@details Subtracts--corresponding elements of input vector from current vector object. User can write command like "u-=v" 
   *
   *@tparam Vector<T>
   *@return Vector<T>
   *
   *@overload 
   */
  const Vector<T>& operator-=(const Vector
  <T>&);
  

      
  /**
  *@brief += operator that takes a scalar as input for the math vector object.
  *@details Adds a scalar to each element of a vector object: User can write command like "u+=a" 
  *
  *
  *@tparam T
  *@return Vector<T>
  *
  *@overload 
  */
  const Vector<T>& operator+=(const T&);
  

        
  /**
  *@brief -= operator that takes a scalar as input for the math vector object.
  *@details Subtracts a scalar from each element of a vector object: User can write command like "u-=a" 
  *
  *@tparam T
  *@return Vector<T>
  *
  *@overload 
  */
  const Vector<T>& operator-=(const T&);
 

          
  /**
  *@brief *= operator that takes a scalar as input for the math vector object.
  *@details Multiplies each elelment of a vector object by a scalar: User can write command like "u*=a" 
  *
  *@tparam T
  *@return Vector<T>
  *
  *@overload 
  */
  const Vector<T>& operator*=(const T&);
  

            
  /**
  *@brief /= operator that takes a scalar as input for the math vector object.
  *@details Divides each elelment of a vector object by a scalar: User can write command like "u/=a" 
  *
  *@tparam T
  *@return Vector<T>
  *
  *@overload 
  */
  const Vector<T>& operator/=(const T&);

  
/**
  *@brief overloaded != operator
  *@details Inputs a vector of unsigned longs which are indices of the vector that are to discarded
  *from the current object.
  *
  *@param Vector<unsigned long>
  *@return Vector<T> 
  *@overload 
  */ 
  const Vector<T>& operator !=(const Vector<T>&);

  const T& operator[](int  i) const;

  
  const Vector<T> operator[](const Vector<int >& v)const;
  
  
  /**
   *@brief Operator to join two vectors
   *
   *@tparam Vector<T>
   *@return Vector<T> A Vector object that is the concatination of
   *current object and new object, in that order.
   */  
  const Vector<T>& operator()(const Vector<T>&);
  

  /**
   *@brief operator() that returns the ith element of a vector
   *
   *@param int index i
   *
   *@return T the i-th element
   */   
  T& operator()(int  i);
  
  const T& get_vec_val(int ) const;

  /**
   *@brief Member function to return the dimension of the vector
   *
   *@return int the number of elements or length of the vector
   *
   */
  const int & get_dimension()const;



  /**
   *@brief << operator
   *
   *\brief user can use cout to display vector object
   */

    friend std::ostream& operator << (std::ostream&out, const Vector<T>&v) {
	int n = v.num_rows;//Vector.dimension;	
	for(int i = 0; i < n; i++) {
           out << v[i] <<"\n";
        }
  
  return out;
  } 

  /**
   *@brief Member to set a value at the i-th index of the vector
   *
   *@param int index or position i
   *@tparam T the value to set to the i-the slot of the vector
   *
   */
  void set_val(int  i, const T& t);


  /**
   *@brief Absolute value of a number
   *
   *@tparam T a real value
   @return T Absolute value of a real number
   */
  /*
  const T abs(T& v);
*/
 /**
 *@brief member function to sort elements of a Vector<T> in ascending order
 *@detail Function a vector of type T that tha has a well defined operator < in it to impose a complete order of of objects of type T
 *
 *
 *@return Vector<T> Sorted data.
 */
 const Vector<T>& sort();
};


/**
  *@brief overloaded minus operator
  *@details Takes a mathematical vector object and subtracts a specified value (real) from each of
  *the vector object elements.
  * 
  *
  *@tparam Vector<T>
  *@tparam T
  *
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator-(const Vector<T>&, const T&);


/**
  *@brief overloaded plus operator
  *@details Takes a mathematical vector object and adds a specified value (real) from each of
  *the vector object elements.
  * 
  *
  *@tparam Vector<T>
  *@tparam T
  *
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator+(const Vector<T>&, const T&);


/**
  *@brief overloaded minus operator
  *@details Takes a mathematical vector object and subtracts a specified value (real) from each of
  *the vector object elements.
  * 
  *
  *@tparam Vector<T>
  *@tparam T
  *
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator-(const T&, const Vector<T>&);


/**
  *@brief overloaded plus operator
  *@details Takes a mathematical vector object and adds a specified value (real) from each of
  *the vector object elements.
  * 
  *
  *@tparam Vector<T>
  *@tparam T
  *
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator+(const T&, const Vector<T>&);



/**
  *@brief overloaded minus operator
  *@details Takes a mathematical vector object and divides a specified value (real) from each of
  *the vector object elements.
  * 
  *
  *@tparam Vector<T>
  *@tparam T
  *
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator/(const T&, const Vector<T>&);


/**
  *@brief overloaded plus operator
  *@details Takes a mathematical vector object and multiplies a specified value (real) from each of
  *the vector object elements.
  * 
  *@tparam Vector<T>
  *@tparam T
  *
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator*(const T&, const Vector<T>&);




/**
  *@brief overloaded minus operator
  *@details Takes a mathematical vector object and divides a specified value (real) from each of
  *the vector object elements.
  * 
  *
  *@tparam Vector<T>
  *@tparam T
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator/(const Vector<T>&, const T&);


/**
  *@brief overloaded plus operator
  *@details Takes a mathematical vector object and multiplies a specified value (real) from each of
  *the vector object elements.
  * 
  *
  *@tparam Vector<T>
  *@tparam T
  *
  *
  *@return Vector<T>
  *
  *@overload 
  */ 
template<typename T>
Vector<T> operator*(const Vector<T>&, const T&);


/**
  *@brief overloaded minus operator
  *@details Computes the difference between corresponding elements of two vectors. The second vector input is subtracted from the first vector.
  * 
  *
  *@tparam Vector<T>
  *@tparam Vector<T>
  *
  *@return Vector<T>
  *
  *@overload 
  */
template<class T>
const Vector<T> operator-(const Vector<T>&, const Vector<T>&);


/**
  *@brief overloaded plus operator
  *@details Computes the sum of corresponding elements of two vectors. The second vector input is subtracted from the first vector.
  * 
  *
  *@tparam Vector<T>
  *@tparam Vector<T>
  *
  *@return Vector<T>
  *
  *@overload 
  */
template<class T>
const Vector<T> operator+(const Vector<T>&, const Vector<T>&);

/**
  *@brief overloaded greater than operator
  *@details compares entries of a vector against a given input.
  * When a vector entry is greater than the input (a real), a corresponding greater
  *than operator inputs a real or an integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator>(const Vector<T>&, const T&);


/**
  *@brief overloaded less than operator
  *@details compares entries of a vector against a given input.
  * When a vector entry is greater than the input (a real), a corresponding less than operator
  *inputs a real or integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator<(const Vector<T>&, const T&);




/**
  *@brief overloaded greater than equal operator
  *@details compares entries of a vector against a given input.
  * When a vector entry is greater than or equal to the input (a real), a corresponding greater
  *than or equal operator inputs a real or an integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator>=(const Vector<T>&, const T&);


/**
  *@brief overloaded less than equal operator
  *@details compares entries of a vector against a given input.
  * When a vector entry is less than or equal input (a real), a corresponding
  *less than or equal operator
  *inputs a real or integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator<=(const Vector<T>&, const T&);




/**
  *@brief overloaded greater than operator
  *@details compares coreesponding entries of two vectors elementwise.
  * When a vector entry is greater than the input (a real), a corresponding greater
  *than operator inputs a real or an integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator>(const Vector<T>&, const Vector<T>&);


/**
  *@brief overloaded less than operator
  *@details compares coreesponding entries of two vectors elementwise.
  * When a vector entry is greater than the input (a real), a corresponding less than operator
  *inputs a real or integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator<(const Vector<T>&, const Vector<T>&);




/**
  *@brief overloaded greater than equal operator
  *@details compares coreesponding entries of two vectors elementwise.
  * When a vector entry is greater than or equal to the input (a real), a corresponding greater
  *than or equal operator inputs a real or an integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator>=(const Vector<T>&, const Vector<T>&);


/**
  *@brief overloaded less than equal operator
  *@details compares coreesponding entries of two vectors elementwise .
  * When a vector entry is less than or equal input (a real), a corresponding
  *less than or equal operator
  *inputs a real or integer value
  *
  *@tparam Vector<T>
  *@tparam T 
  *@overload 
  */ 

template<typename T>
Vector<bool> operator<=(const Vector<T>&, const Vector<T>&);





/**
  *@brief overloaded Bitwise OR operator
  *@details Does bitwise OR operations on corresponding (index wise) elements from two vectors.
  *  * When a vector entry is greater than the input (a real), a corresponding greater
  *than operator inputs a real or an integer value
  *
  *@tparam Vector<T>
  *@tparam Vector<T> 
  *@overload 
  */ 
template<typename T>
Vector<bool> operator|(const Vector<T>&, const Vector<T>&);




/**
  *@brief overloaded Bitwise AND operator
  *@details Does bitwise OR operations on corresponding (index wise) elements from two vectors.
  *  * When a vector entry is greater than the input (a real), a corresponding greater
  *than operator inputs a real or an integer value
  *
  *@tparam Vector<T>
  *@tparam Vector<T> 
  *@overload 
  */ 
template<typename T>
Vector<bool> operator&(const Vector<T>&, const Vector<T>&);


/**
 *@brief Ordinary function that computes the square of l2 norm of a vector
 *
 *@tparam Vector<T>
 *
 *return T the square of l2 norm of a vector
 *
 */
template<class T>
T l2norm_sq(const Vector<T>&);



/**
 *@brief Ordinary function that computes the l2 norm of a vector
 *
 *@tparam Vector<T>
 *
 *return T the l2 norm of a vector
 *
 */
template<class T>
const T l2norm(const Vector<T>&);


/**
 *@brief Displays vector elements at the console
 *
 *@tparam Vector<T>
 *
 */
template<typename T>
void disp_vec(const Vector  <T>&);

/**
  *@brief ordinary function PruneVector 
  *@details Removes elements of second input from first input, if they exist.
  * 
  *
  *@tparam Vector<T>
  *@tparam Vector<T>
  *@return Vector<T> 
  *@overload 
  */ 
template<typename T>
Vector<T> prune_vec(const Vector<T>&, const Vector<T>&);




/**
 *@brief Permutation function.
 *@detail Function takes a vector of indices, and data vector and sorts data based
 *on the desired permutation
 *
 *@tparam Vector<int > indices of desired permutation
 *@tparam MathVecotr<T> data to be sorted
 *@return Vector<T> Sorted data.
 */
template<typename T>
Vector<T> perm(const Vector<int >&,
                            const Vector<T>&);


/**
 *@brief Function to slice Vector Object
 *
 *@tpatam Vector<T>
 *@param int , start index
 *@param int , slice val less that vector length
 *@param int , end index
 *@return Vector<T>, sliced vector
 *
 */
template<typename T>
const Vector<T> slice(const Vector<T>&, const canal::Lseq&);
/**
 *@brief Pointwise vector multiplication: multiply corresponding vector elements
 *
 *@tparam Vector<T>
 *@tparam Vector<T>
 *@return Vector<T>
 */
template<typename T>
const Vector<T> elem_mult(const Vector<T>&, const Vector<T>&);

/**
 *@brief Pointwise vector division: divide corresponding vector elements
 *
 *@tparam Vector<T>
 *@tparam Vector<T>
 *@return Vector<T>
 */
template<typename T>
const Vector<T> elem_div(const Vector<T>&, const Vector<T>&);

/**
 *@brief Ordinary fucntion to join to vectors
 *
 *@tparam Vector<T>
 *@tparam Vector<T>
 *@return Vector<T>
 */
template<typename T>
const Vector<T> concat_vec(const Vector<T>&, const Vector<T>&);


/**
 *@brief Ordinary fucntion to find indices corresponding true (boolean) of an input vector
 *
 *@param Vector<boolean>
 *
 *@return Vector<unsigned long> 
 */
const Vector<int > find(const Vector<bool>&);


/**
 *@brief Ordinary fucntion to find minimum a Vector 
 *
 *@tparam Vector<T>
 *
 *@return T 
 *
 */
template<typename T>
const T min(const Vector<T>&);


/**
 *@brief Ordinary fucntion to find maximum value of a Vector
 *
 *@tparam Vector<T>
 *
 *@return T 
 *
 */
template<typename T>
const T max(const Vector<T>&);

/**
 *@brief Ordinary fucntion to compute the differences of a vector object entries
 *@details This function can the forward and backward differences of a vector object 
 *
 *@tparam Vector<T>
 *@param string option for forward ("f") or backward ("b") differences. 
 *
 *@return Vector<T> of differences
 */
template<typename T>
const Vector<T> diff(const Vector<T>&v, const std::string s = "f");


 /**
 *@brief Ordinary fucntion to find absolute value of each element of a given vector
 *
 *@tparam Vector<T> 
 *
 *@return Vector<T> absolute values
 */

template<typename T>
const Vector<T> abs_vec(const Vector<T>& v);


/**
 *@brief Ordinary function that computes the sum of a Vector of type T
 *
 *@tparam Vector<T>
 *
 *@return T
 */
template<typename T>
const T sum(const Vector<T>&);

}//  end namespace

}//end namespace
#include "math_vector.cpp"
#endif
