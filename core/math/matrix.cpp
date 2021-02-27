#include "core/math/matrix.hpp"
#include "data_struct/lists/list.hpp"
namespace canal {
namespace math {
//constructors
template<class T>
Matrix<T>::Matrix(const  int& m, const  int& n):num_rows2(m), Vector<Vector<T > >(n)
{
 Vector<T> v(m);//vector of zeros
  for( int i = 0; i < n;i++)
     Vector<Vector<T> >::element[i] = v; 
 //Vector<Vector<T>> vv(n,v);
 

}


template<class T>
Matrix<T>::Matrix(const  int& m, const  int& n, const T& t) :num_rows2(m) , Vector< Vector<T> >(n)
{
  
  Vector<T> v(m,t);
  //Vector<Vector<T>> vv(n,v);
  
  for ( int i = 0; i < n;i++)
     Vector<Vector<T> >::element[i] = v;

/*
  for ( int i = 0; i < n;i++)
     Vector<Vector<T> >::element[i] = new T[m];
 */
/*
  for( int i = 0; i < n;i++)
     Vector<Vector<T> >::element[i] = vv[i];
  */
}


template<class T>
Matrix<T>::Matrix(const  int& n, const Vector<T>&v): Vector<Vector<T> >(n), num_rows2(v.get_dimension() ) 
{
  for( int i = 0; i < n;i++)
     Vector<Vector<T> >::element[i] = v;
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& m) : Vector<Vector<T> >(m.num_rows), num_rows2(m.num_rows2)
{
  for( int i = 0; i < m.num_rows;i++)
    {
      Vector<Vector<T> >::element[i] = m.element[i];
           
    }
}


// -------------------------------------------------------------------------------------

template<typename T>
 int Matrix<T>::get_max_val_index(const Vector<T>& v, const  int& k)
{
   int j = 0;
  for( int i = k; i<v.get_dimension(); i++)
    {
      if(abs(v[i]) > abs(v[j]) )
         j = i;
    }
   return j;
}


// --------------------------------------------------------------------------------------
template<class T>
void Matrix<T>::set_val( int i,  int j, const T&t)
{
  Vector<Vector<T> >::element[j](i) = t; 
}

//----------------------------------------------------------------------------------------
template<class T>
const Vector<T>& Matrix<T>::operator[](int i) const {
  return Vector<Vector<T>>::element[i];
}

// ---------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
template<class T>
void Matrix<T>::set_val(Lseq x, Lseq y, const Matrix<T>& M) {

   int row_start = x.start_idx;
   int row_end = x.end_idx;
   int row_incr = x.incr;
   int col_start = y.start_idx;
   int col_end = y.end_idx;
   int col_incr = y.incr;

   if (row_end < row_start || col_end < col_start) {
     std::cout <<"Error: end inde is lower than start index" <<"\n";
     return;
   }

   if ( row_end >= num_rows2 || col_end >= Vector<Vector<T> >::num_rows ) {
     std::cout<< "Error: indices out of bounds" <<"\n";
     return;
   }

   if ( row_start < 0 || col_start < 0 ) {
     std::cout<<"Error: start index cannot be less than zero" <<"\n";
     return;
   }
  
   int n_rows = (row_end - row_start) + 1;
   int n_cols = (col_end - col_start) + 1;

   if (n_rows > M.get_num_rows() || n_cols > M.get_num_cols() ) {
     std::cout<< "Error: indexing range is greater than input Matrix" <<"\n";
     return;
   }

   int idx_col, idx_row = 0;
   for (int i = row_start; i < row_end+1; i+=row_incr) {
     idx_col = 0;
     for (int j = col_start; j < col_end+1; j+=col_incr) {
       Vector<Vector<T> >::element[j](i) = M[idx_col][idx_row];
       idx_col++;
     }
     idx_row++;
   }

}


template<class T>
const Matrix<T>  Matrix<T>::transpose() {

  Vector<T> v_tmp(Vector<Vector<T> >::num_rows);
  Matrix<T> m(Vector<Vector<T> >::num_rows, num_rows2);
  //delete [] Vector<Vector<T> >::element;
  //Vector<Vector<T> >::element = new Vector<T>[m.num_rows];
  //Vector<Vector<T> >::num_rows = m.num_rows2;
  //num_rows2 = m.num_rows;
	
  for(int i=0; i<num_rows2; i++){
    for (int j = 0; j < Vector<Vector<T> >::num_rows; j++) {
      v_tmp.set_val(j, Vector<Vector<T> >::element[j][i]);
    }
    m.set_val(i, v_tmp);	
  }
  
  return m;
}


template<class T>
int Matrix<T>::get_num_rows()const
{
  return num_rows2;//Vector<Vector<T> >::num_rows;
}

template<class T>
 int Matrix<T>::get_num_cols()const
{
  return Vector<Vector<T> >::num_rows; //num_rows2;
}

//----------------------------------------------------------------------------------------

template<class T>
void Matrix<T>::set_val( int i, const Vector<T>&v)
{
  Vector<Vector<T> >::element[i] = v;  
}


//----------------------------------------Operator Functions-----------------------------
template<class T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
{
  if( this != &m)
    {
      if(Vector<Vector<T> >::num_rows != m.num_rows || num_rows2 !=m.num_rows2)
	{
         delete [] Vector<Vector<T> >::element;
         Vector<Vector<T> >::element = new Vector<T>[m.num_rows];
	 Vector<Vector<T> >::num_rows = m.num_rows;
	 num_rows2 = m.num_rows2;
	}      
      
      for( int i=0; i<m.num_rows; i++){
      	Vector<Vector<T> >::element[i] = m.element[i];	
       }
    }
  return *this;
}//Assignement operator


template<class T>
const Matrix<T>& Matrix<T>::operator+=(const T& t)
{
  for( int i = 0; i < Vector<Vector<T> >::num_rows; i++)
    Vector<Vector<T>>::element[i] += t;//vector plus constant already defined in Vector class
  return *this;
}


template<class T>
const Matrix<T>& Matrix<T>::operator+=(const Vector<T>& v)
{
  
  throw_assert(v.get_dimension()==num_rows2, "Mismatch! Check vector length")
  for( int i = 0; i < Vector<Vector<T> >::num_rows; i++)
    Vector<Vector<T>>::element[i] += v;
  return *this;
}

template<class T>
const Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& m)
{
  
  throw_assert(Vector<Vector<T> >::num_rows==m.num_rows && num_rows2==m.num_rows2, "Matrices are not same size");
  for( int i = 0; i<m.num_rows; i++)
    Vector<Vector<T> >::element[i] += m.element[i];
  return *this;
}



template<class T>
const Matrix<T>& Matrix<T>::operator-=(const T& t)
{
  for( int i = 0; i < Vector<Vector<T>>::num_rows; i++)
    Vector<Vector<T>>::element[i] -= t;//vector minus constant already defined in Vector class
  return *this;
}


template<class T>
const Matrix<T>& Matrix<T>::operator-=(const Vector<T>& v)
{
  
  throw_assert(v.get_dimension()==num_rows2, "Mismatch! Check vector length");
  for( int i = 0; i < Vector<Vector<T>>::num_rows; i++)
    Vector<Vector<T>>::element[i] -= v;
  return *this;
}

template<class T>
const Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& m)
{
  throw_assert(Vector<Vector<T>>::num_rows==m.num_rows && num_rows2==m.num_rows2, "Matrices are not same size");
  for( int i = 0; i<m.num_rows; i++)
    Vector<Vector<T> >::element[i] -= m.element[i];
  return *this;
}

//---------------------------------Multiplication--------------------------------------
template<class T>
    const Matrix<T>& Matrix<T>::operator*=(const T& t)
{
  for ( int i = 0; i < Vector<Vector<T>>::num_rows; ++i) {
    Vector<Vector<T> >::element[i] *= t;
  }
  return *this;

}


template<class T>
const Matrix<T>& Matrix<T>::operator*=(const Vector<T>& v)
{
  
  throw_assert(v.get_dimension()==Vector< Vector<T> >::num_rows, "Mismatch! Check vector length");
       
  Vector<T> v_tmp(v.get_dimension()), v_tmp2(Vector< Vector<T> >::element[0].get_dimension());//number of columns
   int n=1, ctr=0; //v.get_dimension
  for ( int i = 0; i < Vector< Vector<T> >::element[0].get_dimension(); i++) {
     for ( int j = 0; j < Vector< Vector<T> >::num_rows; j++) {
        v_tmp.set_val(j, Vector< Vector<T> >::element[j](i) );
      }
      v_tmp2.set_val(i,  v_tmp*v); // operator * of Vector returns dot product 
      
    }
    
    num_rows2 = Vector< Vector<T> >::element[0].get_dimension();
    delete [] Vector< Vector< T > >::element;
    Vector< Vector<T> >::element = new Vector<T>[n];
    Vector< Vector<T> >::num_rows = n;
    
    Vector< Vector< T > >::element[0] = v_tmp2;
    return *this;
  
}




template<class T>
const Matrix<T>& Matrix<T>::operator%=(const  int& n)
{
  delete [] Vector<Vector<T> >::element;
  Vector<Vector<T> >::element = new Vector<T> [n];
  Vector<Vector<T> >::num_rows = n;
  num_rows2 = n;
  for ( int i = 0; i < n; i++) {
    Vector<T> v(n, i, 1);
    Vector<Vector<T> >::element[i] = v;
  }
  return *this;  
}



template<class T>
const Matrix<T>& Matrix<T>::operator/=(const T&t)
{
   for ( int i = 0; i < Vector<Vector<T>>::num_rows; ++i) {
    Vector<Vector<T> >::element[i] /= t;
  }
  return *this;
}


template<class T>
const Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& m)
{
  throw_assert(Vector<Vector<T>>::num_rows==m.get_num_rows(), "Mismatch! Check vector length");//number of columns of current matrix object vs number of rows of input matrix object.
  Matrix<T> m_tmp = *this; 
  delete [] Vector<Vector<T>>::element;
  Vector<Vector<T>>::element = new Vector<T>[m.get_num_cols()];

  for ( int i = 0; i < m.get_num_cols(); i++) {
    Vector<T> v_tmp(m_tmp.get_num_rows());
    for ( int j = 0; j < m_tmp.get_num_cols(); j++) {
      v_tmp += m_tmp[j] * m[i][j];      
    }
    Vector< Vector<T> >::element[i] = v_tmp;    
  }
  Vector< Vector<T> >::num_rows = m.get_num_cols();

  return *this;
}


//---------------------------End Operator Functions-------------------------------------

//---------------------------Non Member Operator Functions------------------------------
template<class T>
Matrix<T> operator*(const Matrix<T>& m, const Matrix<T>&m2)
{
  return Matrix<T> (m) *= m2;
}


template<class T>
Matrix<T> operator*(const Matrix<T>& m, const Vector<T>&v)
{
  return Matrix<T> (m) *= v;
}



template<class T>
Matrix<T> operator*(const Matrix<T>& m, const T& t)
{
  return Matrix<T> (m) *= t;
}



template<class T>
Matrix<T> operator*(const T& t, const Matrix<T>& m)
{
  return Matrix<T> (m) *= t;
}


template<class T>
Matrix<T> operator/(const Matrix<T>&m, const T&t)
{
  return Matrix<T>(m) /= t;
}


template<class T>
Matrix<T> operator/( const T&t, const Matrix<T>&m )
{
  return Matrix<T>(m) /= t;
}




template<class T>
Matrix<T> operator+(const Matrix<T>&m, const T&t)
{
  return Matrix<T>(m) += t;
}


template<class T>
Matrix<T> operator+(const T&t, const Matrix<T>&m)
{
  return Matrix<T>(m) += t;
}


template<class T>
Matrix<T> operator+(const Matrix<T>&m, const Vector<T>&v)
{
  throw_assert(v.get_dimension()==m[0].get_dimension(), "Mismatch! Check vector length")
  return Matrix<T>(m) += v;
}


template<class T>
Matrix<T> operator+(const Vector<T>&v, const Matrix<T>&m)
{
  throw_assert(v.get_dimension()==m[0].get_dimension(), "Mismatch! Check vector length")
  return Matrix<T>(m) += v;
}


template<class T>
const Matrix<T> operator+(const Matrix<T>&m, const Matrix<T>&n)
{
  throw_assert(m.get_num_cols()==n.get_num_cols() && m.get_num_rows()==n.get_num_rows(), "Matrices are not same size");
  return Matrix<T>(m) +=  n;
}



template<class T>
Matrix<T> operator-(const Matrix<T>&m, const T&t)
{
  return Matrix<T>(m) -= t;
}


template<class T>
Matrix<T> operator-(const T&t, const Matrix<T>&m)
{
  return Matrix<T>(m) -= t;
}


template<class T>
Matrix<T> operator-(const Matrix<T>&m, const Vector<T>&v)
{
  throw_assert(v.get_dimension()==m[0].get_dimension(), "Mismatch! Check vector length")
  return Matrix<T>(m) -= v;
}



template<class T>
const Matrix<T> operator-(const Matrix<T>&m, const Matrix<T>&n)
{
  throw_assert(m.get_num_cols()==n.get_num_cols() && m.get_num_rows()==n.get_num_rows(), "Matrices are not same size");
  return Matrix<T>(m) -=  n;
}


//-------------------------End Non Member Operator Functions-----------------------------------


template<class T>
Matrix<T> eye(const  int n, const T& t)
{
  Matrix<T>m(n,n);
  
  return Matrix<T>( Matrix<T> (m) %= n)*=t;
  
  
}







//-------------------------Other Non Memeber Functions------------------------------------------


template<class T>
void disp_matrix(const Matrix<T>& m)
{
  
  for( int i=0; i < m.get_num_rows(); i++)
    {
      for( int j = 0; j<m.get_num_cols(); j++)
	std::cout<<m[j][i]<<" ";
      std::cout<<"\n";
    }
    
}
/*
template<class T>
Matrix<T> GrahmSchmidt(const Matrix<T>& m)
{
  
  return Matrix<T>(m) %= m;
}

*/

/*
template<class T>
Matrix<T> HouseHolder(const Matrix<T>& m)
{
  return Matrix<T>(m) % m;
}
*/

template<class T>
const Vector<canal::math::Complex<T> > EigenVal(const Matrix<T>&M)
{

  //assert that this is a square matrix
   int n = M.get_num_cols();
  Vector<canal::math::Complex<T>> lambda(n);
  Eigen::MatrixXd A = Eigen::MatrixXd::Constant(n,n,0);
  std::complex<double> c;
  canal::math::Complex<double> c1;
  for( int i = 0; i < n; i++)
  {
    for( int j = 0; j < n; j++)
    {
      A(i,j) = M[j][i];
    }                                                                                                
  }
  

  
  Eigen::EigenSolver<Eigen::MatrixXd> es(A);
  for( int i = 0; i < n; i++)
  {
    c = es.eigenvalues()[i];
    c1.set_re( c.real() );
    c1.set_im( c.imag() );
    lambda.set_val(i, c1);
  }

  return lambda;   
}

 template<typename T>
 const Matrix<T> slice(const Matrix<T>& M, const canal::Lseq& x, const canal::Lseq& y) {

   int row_start = x.start_idx;
   int row_end = x.end_idx;
   int row_incr = x.incr;
   int col_start = y.start_idx;
   int col_end = y.end_idx;
   int col_incr = y.incr;

   if (row_end < row_start || col_end < col_start) {
     std::cout <<"Error: end inde is lower than start index" <<"\n";
     return 0;
   }

   if ( row_end >= M.get_num_rows() || col_end >= M.get_num_cols() ) {
     std::cout<< "Error: indices out of bounds" <<"\n";
     return 0;
   }

   if ( row_start < 0 || col_start < 0 ) {
     std::cout<<"Error: start index cannot be less than zero" <<"\n";
     return 0;
   }
  
   int n_rows = (row_end - row_start) + 1;
   int n_cols = (col_end - col_start) + 1;
   
   Matrix<T> A(n_rows, n_cols);
   
   int ctr_r, ctr_c = 0;
   for (int i = col_start; i < col_end+1; i+=col_incr) {
     ctr_r = 0;
     for (int j = row_start; j < row_end+1; j+=row_incr) {
       A.set_val(ctr_r,ctr_c, M[i][j]);
       ctr_r ++;
     }
     ctr_c ++;
   }

   return A; 

  
 }



}
} //End Namespace
