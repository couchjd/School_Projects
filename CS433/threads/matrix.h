#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <string>

class Matrix{
 public:
  Matrix();
  Matrix(const Matrix&);
  Matrix(Matrix* matIn);
  Matrix(const char* fileName);
  Matrix(const int&, const int&);
  ~Matrix(){
    for (int i = 0; i < m_rows; i++){
      delete [] m_mat[i];
    }
    delete [] m_mat;
  } //end destructor

  int m_mode;
  int** m_mat;
  int getRows() const {return m_rows;}
  int getCols() const {return m_cols;}
  void printMat();
  Matrix operator* (const Matrix&) const;
  Matrix operator= (const Matrix& matB);

  friend Matrix serialMult(const Matrix& matA, const Matrix& matB);
  friend Matrix parallelMult(Matrix matA, Matrix matB);

 protected:
  int m_rows;
  int m_cols;

  void init(const char* fileName);
};
#endif
