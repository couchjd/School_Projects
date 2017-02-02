#include "matrix.h"
#include <stdlib.h>

using namespace std;
Matrix::Matrix(){
  m_rows = 0;
  m_cols = 0;
  m_mat = NULL;
}
Matrix::Matrix(const char* fileName){
  size_t len = 0;
  char* line;
  FILE* fp;
  int num;

  fp = fopen(fileName, "r");

  getline(&line, &len, fp);
  m_rows = atoi(line);
  getline(&line, &len, fp);
  m_cols = atoi(line);

  this->m_mat = new int*[m_rows];
  for (int i = 0; i < m_rows; i++){
    this->m_mat[i] = new int[m_cols];
  }

  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      fscanf(fp, "%d", &num);
      this->m_mat[x][y] = num;
    }
  }
  fclose(fp);
}

Matrix::Matrix(Matrix* matIn){
  m_rows = matIn->getRows();
  m_cols = matIn->getCols();
  m_mat = new int*[m_rows];
  for (int i = 0; i < m_rows; i++){
    m_mat[i] = new int[m_cols];
  }

  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      m_mat[x][y] = 0;
    }
  }

  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      this->m_mat[x][y] = matIn->m_mat[x][y];
    }
  }
}

Matrix::Matrix(const Matrix& matIn){
  m_rows = matIn.getRows();
  m_cols = matIn.getCols();
  m_mat = new int*[m_rows];
  for (int i = 0; i < m_rows; i++){
    m_mat[i] = new int[m_cols];
  }

  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      m_mat[x][y] = 0;
    }
  }

  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      this->m_mat[x][y] = matIn.m_mat[x][y];
    }
  }
}
Matrix::Matrix(const int& rowsIn, const int& colsIn){
  m_rows = rowsIn;
  m_cols = colsIn;

  m_mat = new int*[m_rows];
  for (int i = 0; i < m_rows; i++){
    m_mat[i] = new int[m_cols];
  }

  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      m_mat[x][y] = 0;
    }
  }
}

Matrix Matrix::operator= (const Matrix& matB){
  m_rows = matB.getRows();
  m_cols = matB.getCols();

  m_mat = new int*[m_rows];
  for (int i = 0; i < m_rows; i++){
    m_mat[i] = new int[m_cols];
  }

  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      this->m_mat[x][y] = matB.m_mat[x][y];
    }
  }
  return this;
}

Matrix Matrix::operator* (const Matrix& matB) const{
  return serialMult(*this, matB);
  printf("TEST MULT OPERATOR\n");
  //return parallelMult(*this, matB);
/*
  switch(m_mode){
    case 0:

      break;
    case 1:
      return parallelMult(*this, matB);
      break;
    case 2:

      break;

    default:
      break;

  }

  //return matC;
*/
}


void Matrix::printMat(){
  for(int x = 0; x < m_rows; x++){
    for(int y = 0; y < m_cols; y++){
      printf("%d", m_mat[x][y]);
      if(y < m_cols){
        printf("%c", ' ');
      }
    }
    printf("%c", '\n');
  }
}

