/**
 *@file matrix.hpp
 *
 *
 *@brief This file contains prototypes for a matrix as a Vector of MahtVectors described in ...
 *
 *
 *   
 *@author Patrick Kasi
 *
 *@bug No known bugs.
 */



#ifndef _MATRIX_H_

#define _MATRIX_H_

#include <iostream>
#include "math_vector.hpp"
#include "complex.hpp"
#include <Eigen/Eigenvalues>
#include "vec_ops/lseq.hpp"



namespace canal {
namespace math {
/**
 * @brief Declares a Matrix object as a vector of a vector of type T.
 * The matrix object is inherited from the Vector object
 * 
 *
 */
template<class T>
class Matrix : public Vector< Vector<T> >
{
protected:
  //Vector<Vector<T>>* element;
   int num_rows2;//refers to number Matrix rows
  /*
  /**
   *@brief Function used for pivoting during Gaussian Elimination
   *@param Vector object
   *@param  int row number where search for max in vector starts
   *return usnigned  int
   */
   int get_max_val_index(const Vector<T>&, const  int&);
public:

  /**
   *@brief Constructor
   *
   *@details COnstructor that initalizes a matrix to zeros
   *
   *@params m number of rows of the matrix object to create of type int
   *@params n the number of columns the matrix object to create (type int)
   *
   * A Matrix object, say a 3 by 5 can be instantiated as follows:
   *
   *   \code{.cpp}
   *   Matrix<double> m(3,5);
   *   \endcode
   *
   */
  Matrix(const  int& m=0, const  int& n=0);

 
  Matrix(const Vector<Vector<T> >&)
  {
  }//implicit converter

   /**
   *@brief A more meaningful constructor that initializes a matrix and instantiated as follow:
   *
   *   \code{.cpp}
   *   Matrix<double> m(3,5, 1.0);
   *   \endcode
   *This will generate a 3 by 5 matrix of doubles all set to 1.0
   *
   *@params m number of rows of the matrix object to create of type int
   *@params n the number of columns the matrix object to create (type int)
   @tparams t a real value of type T which is set to all elements of a matrix
   */
  Matrix(const int&, const int&, const T&);

   /**
   *@brief Another constructor that inputs a vector object of type T
   * Here, since the matrix is a vector of vectors, each column of the matrix
   * is set to the input vector (matrix initialization based on vector input)
   *
   *
   *@params n the number of columns (type int)
   @tparams Vector<T> a vector of real values which is set to all elements (columns) of a matrix
   */
  Matrix(const int&, const Vector<T>&);

   /**
   *@brief A copy constructor
   *
   *@tparams Matrix<T> a real values which is set to all elements of the current matrix object
   */
  Matrix(const Matrix<T>&);

   /**
   *@brief A destructor
   *
   */
  ~Matrix()
  {
    
  }


  

  /**
   * @brief This function returns the number of columns of the matrix object
   */
  int get_num_cols()const;

   /**
   * @brief This function returns the number of rows of the matrix object
   */
  int get_num_rows()const;

  /**
   *@brief member function that enters an element into a desired position of a matrix
   *
   *@param i Row number or id of type integer
   *@param j Column number of type integer
   *@tparam t the i,j th element of matrix object of type T
   */
  void set_val(int, int, const T&);

  /**
   *@brief member function that enters more than one element (block) into desired positions of a matrix
   *
   @param x Lseq type that specifies start index, end index and increment for rows
   @param y Lseq type that specifies start index, end index and increment for columns
   *
   *  \code{.cpp}
   *   canal::math::Matrix<double> m(5,5), n(3,1);
   *   std::cout<< m << "\n";
   *   std::cout<< n << "\n";
   *   m.set(Lseq(2,4,1), Lseq(0,0,1), n);
   *   std::cout<< m <<"\n";
   *   \endcode
   */
  void set_val(Lseq, Lseq, const Matrix<T>&);

  /**
   *@brief Transpose a matrix
   *
   *tparam m Matrix object to transpose
   *
   *@return mt tranposed Matrix object
   */
  const Matrix<T> transpose();
  
    /**
   *@brief member function that enters a vector element into a desired column position of a matrix
   *
   *@param i column number (integer type)
   *@tparam v a Vector<T>
   */
  void set_val(int, const Vector<T>&);


  /**
   *@brief Read only operator
   *
   *@param i the i-th colum of a matrix as a Vector object
   *@return v Vector of type t
   *
   *@overload
   */
  const Vector<T>& operator[](int) const;

  

  /**
   *@brief Assignment operator
   * Can write
   *
   *    \code{.cpp}
   *    canal::math::Matrix<double> m, n(3,5,2.3);
   *    m = n;
   *    \endcode
   *@tparam n a matrix object of type T
   *
   *@return m a matrix object that is equal to another matrix object n
   */
  const Matrix<T>& operator=(const Matrix<T>&);

  /**
   *Addition Assignment operator that take a type T and adds to
   *each elemnt of a Matrix object
   *
   *@tparam t a real of type T
   *
   *@return m a matrix of type T with t added to each matrix element 
   *
   *@overload
   */  
  const Matrix<T>& operator+=(const T&);

  
  /**
   *Addition Assignment operator that take a Vector<T> and adds to
   *each column of a Matrix object
   *
   *@tparam v a vector object of type T
   *
   *@return m a matrix object of type with v added to each column
   *
   *@overload
   */
  const Matrix<T>& operator+=(const Vector<T>&);

  /**
   *@brief Addition Assignment operator that take a Matrix and adds to the current  
   * Matrix object
   *
   *@tparam m th input matrix of type T
   *
   *
   *@return n the current modified matrix object
   *@overload
   */
  const Matrix<T>& operator+=(const Matrix<T>&);

 /**
   *Subtraction Assignment operator that take a type T and subtracts from 
   *each elemnt of a Matrix object
   *
   *@tparam t a real value that is subtracted from each element of the matrix object
   *
   *@return m matrix object
   *
   *@overload
   */
  const Matrix<T>& operator-=(const T&);

  
  /**
   *Subtraction Assignment operator that take a Vector<T> and subtracts from
   *each column of a Matrix object
   *
   *
   *@tparam v a Vector object of type T
   *
   *@return m a Matrix object of type T
   
   *
   *@overload
   */
  const Matrix<T>& operator-=(const Vector<T>&);


  /**
   *Subtraction Assignment operator that take a Matrix objects and subtracts from the current
   * Matrix object 
   *
   *@tparam m a Matrix object of type T
   *
   @return m a Matrix object of type T
   *
   *@overload
   */  
  const Matrix<T>& operator-=(const Matrix<T>&);


  
  /**
   *Addition Assignment operator that take a T and multiplies 
   *each element of a Matrix object
   *
   *
   *@tparam t real of type T
   *
   @return m a Matrix of type T
   *@overload
   */
  const Matrix<T>& operator*=(const T&);


  /**
   *Multiplication Assignment operator that take a math_vecto<T> and multiplies with 
   * Matrix
   *
   *@tparam v a Vector object
   *
   *@return m a matrix object
   *@overload
   */  
  const Matrix<T>& operator*=(const Vector<T>&);


  /**
   *Multiplication Assignment operator that take a Matrix and multiplies it with another  
   * Matrix
   *The current implementation is a naive approach which runs in O(N^3)
   *Future version will take advantage of an efficient approach such as interfacing with LAPACK
   *
   *@tparam m Matrix object
   *
   *@return  m Matrix object
   *@overload
   */
  const Matrix<T>& operator*=(const Matrix<T>&);

  
 
  /**
   * @brief Mode Assignement Operator
   * Operator inputs an integer and generates an identity matrix if size n X n
   *
   * @param n the size of a square matrix
   * @return m Matrix object
   *
   * @overload
   */
  const Matrix<T>& operator%=(const  int&);


  /**
   *@brief Division Assignement Operator
   *
   *@tparam t a real 
   *@return m Matrix object
   *
   *@overload
   */
   const Matrix<T>& operator/=(const T&);  



/**
   *@brief << operator to over load the cout operator
   *
   *@tparam m a matrix object of type T
   *
   *
   *@overload
   *\brief user can use cout to display matrix object
   */

    friend std::ostream& operator << (std::ostream&out, const Matrix<T>&m) {
	
        for (auto n1 = m.get_num_rows(), i = n1*0; i < n1; i++) {
	   for (auto n2 =  m.get_num_cols(), j = n2*0; j <  n2; j++) { 
               out << m[j][i] <<" ";
           }
           out << "\n";
        }
  
  return out;
  }



};



// -----------------------------Non Member Operator Functions-------------------------
/*
/**
 *@brief Generate the tranpose of a given matrix 
 *@tparam m a matrix object of type T
 *
 *@return n Matrix<T> that is the transpose of the input matrix
 */

//template<class T> Matrix<T> transpose(const Matrix<T>&);



/**
 *@brief Generate a square matrix whose diagonals are equal to a and all other entires are zero
 *@param m an integer matrix size
 *
 *@tparam a The value to put on the diagonal of the matrix of type T
 *
 *@return m Matrix<T> object with zeros else where except the diagonal
 *
 */
template<class T>
Matrix<T> eye(const  int, const T&);



/**
 *@brief Operator function * of Matrix object times a Matrix object
 *
 *@tparam m Matrix<T> object
 *
 *@tparam n Matrix<T> object
 *
 *@return p Matrix<T> object
 */
template<class T>
Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&);


/**
 *@brief Operator function * of Matrix object times a Vector object
 *
 *@param m a Matrix<T> object
 *@param v a Vector<T> object
 *@return p a Matrix<T> object 
 */
template<class T>
Matrix<T> operator*(const Matrix<T>&, const Vector<T>&);


/**
 *
 *@brief Operator to multiply a matrix by a constant
 *
 *@details Each matrix element is scaled by a constant
 *
 *@tparam m a Matrix object of type T
 *@tparam t a real value of type T
 *
 *@return m a Matrix object of type T
 */
template<class T>
Matrix<T> operator*(const Matrix<T>&, const T&);


/**
 *
 *@brief Operator to multiply a constant by a matrix
 *
 *@details Each matrix element is scaled by a constant
 *
 *@tparam t a real value of type T
 *
 *@tparam m Matrix of type T
 *
 *@return m A matrix of type T
 */
template<class T>
Matrix<T> operator*(const T&, const Matrix<T>&);



/**
 *
 *@brief Operator to divide a matrix by a constant
 *
 *@details Each matrix element is scaled by a constant
 *
 *@tparam m a Matrix object of type T
 *@tparam t a real value of type T
 *
 *@return m a Matrix object of type T
 */
template<class T>
Matrix<T> operator/(const Matrix<T>&, const T&);


/**
 *
 *@brief Operator to divide a constant by a matrix
 *
 *@details Each matrix element is scaled by a constant
 *
 *@tparam t a real value of type T
 *
 *@tparam m a Matrix object of type T
 *
 *@return p a Matrix object of type T
 */
template<class T>
Matrix<T> operator/(const T&, const Matrix<T>&);


/**
 *
 *@brief Operator to add a constant to a matrix
 *
 *@details Each matrix element is incremented by a constant
 *
 *@tparam m a Matrix object of type T
 *@tparam t a real value of type T
 *
 *@return p a matrix object of type T
 */
template<class T>
Matrix<T> operator+(const Matrix<T>&, const T&);


/**
 *
 *@brief Operator to add a matrix to constant
 *
 *@details Each matrix element is incremented by a constant
 *
 *@tparam m Matrix of type T
 *@tparam t a real value of type T
 *
 *@return m A matrix of type T
 */
template<class T>
Matrix<T> operator+(const T&, const Matrix<T>&);


/**
 *
 *@brief Operator to add a matrix to constant
 *
 *@details Each matrix element is incremented by a constant
 *
 *@tparam v a Vector object of real value(s) of type T
 *@tparam m a Matrix of real values of type T
 *
 *@return p a Matrix object of type T
 */
template<class T>
Matrix<T> operator+(const Vector<T>&, const Matrix<T>&);



/**
 *@brief Operator to add vector to each matrix column
 *@tparam m a Matrix object of type T
 *
 *@tparam v a Vector object of type T
 *
 *@return p a Matrix object
 *
 * For example one could write:
 *    \code{.cpp}
 *    canal::math::Matrix<double> m(3,5,2.3);
 *    canal::math::Vector<double> n(3,1.25);
 *    m = m + n;
 *    \endcode
 */
template<class T>
Matrix<T> operator+(const Matrix<T>&, const Vector<T>&);




/**
 *@brief Operator to add vector to each matrix column
 *
 *@tparam m a Matrix object of type T
 *
 *@tparam v a Vector object of type T
 *
 *@return p a Matrix object
 */
template<class T>
Matrix<T> operator+(const Vector<T>&, const Matrix<T>&);



/**
 *
 *@brief Operator to add two matrices
 *
 *@tparam m a Matrix object of type T
 *
 *@tparam n a Matrix object of type T
 *
 *@return p a Matrix object of type T
 *
 *
 * * For example one could write:
 *    \code{.cpp}
 *    canal::math::Matrix<double> m(3,5,2.3), n(3,5,1.25);
 *    m = m + n;
 *    \endcode
 */
template<class T>
const Matrix<T> operator+(const Matrix<T>&, const Matrix<T>&);



/**
 *
 *@brief Operator to subtract a constant to a matrix
 *
 *@details Each matrix element is decremented by a constant
 *
 *@tparam m Matrix of type T
 *@tparam t a real value of type T
 *
 *@return n A matrix of type T
 */
template<class T>
Matrix<T> operator-(const Matrix<T>&, const T&);


/**
 *
 *@brief Operator to subtract a matrix from a real of type T
 *
 *@details Each matrix element is decremented by a constant
 *
 *@tparam t a real value of type T
 *
 *@tparam M a Matrix of type T
 *
 *
 *@return M a matrix of type T
 */
template<class T>
Matrix<T> operator-(const T&t, const Matrix<T>&m);



/**
 *
 *@brief Operator to subtract a vector object from a matrix
 *
 *@details Each matrix column is element-wise decremented by the input vector
 *
 *@tparam M a matrix type T
 *
 *@tparam v a vector of type T
 *
 *
 *@return B A matrix of type T
 */
template<class T>
Matrix<T> operator-(const Matrix<T>&, const Vector<T>&);




/**
 *@brief Operator function - of Matrix object minus a Matrix object
 *
 *@param A Matrix<T>
 *@param B Matrix<T>
 *@return C Matrix<T> the difference matrix
 */
template<class T>
const Matrix<T> operator-(const Matrix<T>&, const Matrix<T>&);

/**
 *@brief Ordinary function to compute eigenvalues of a matrix
 *
 *@details This fucntion is a wrapper (relies on Eigen library) and basically returns a vector of eigen values. The current implementation of the Eigen C++ library assumes that the input matrix is real
 *
 *@tparam m a Matrix<T> where T is of type reals
 *@return v Vector of type canal::math::Complex<T>
 *
 */
template<class T>
const Vector<canal::math::Complex<T> > EigenVal(const Matrix<T>&);




/**
 *@brief matrix slicing function
 *@details Functionality to slice a matrix and return a submatrix as desired.
 * 
 *
 *@tparam  m A matrix object Matrix<T> to be sliced
 *@param x matrix row indexing Lseq (linear sequence) type which provides start, end, and an increment
 *@param y matrix column indexing Lseq (linear sequence) type which provides start, end, and increment
 
 *@return v a sliced matrix object 
 */
template<typename T>
const Matrix<T> slice(const Matrix<T>&, const canal::Lseq&, const canal::Lseq&);

}
} //End Name space
 #include "matrix.cpp"
#endif
