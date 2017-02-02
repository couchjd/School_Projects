#include <unistd.h>
#include <sys/time.h>
#include "matrix.h"

struct timeval serialT1, serialT2;
double serialTime;

double serial(const Matrix* matA, const Matrix* matB){
  gettimeofday(&serialT1, NULL);

  Matrix matC((*matA) * (*matB));
  printf("CALCULATING SERIALLY:\n");
  matC.printMat();
  //printf("\n");

  gettimeofday(&serialT2, NULL);
  serialTime = (serialT2.tv_sec - serialT1.tv_sec) * 1000.0;      // sec to ms
  serialTime += (serialT2.tv_usec - serialT1.tv_usec) / 1000.0;
  return serialTime;
}

Matrix serialMult(const Matrix& matA, const Matrix& matB){
  Matrix matC(matA.getRows(), matB.getCols());
  for(int i = 0; i < matA.getRows(); i++){
    for(int j = 0; j < matB.getCols(); j++){
      for(int k = 0; k < matA.getCols(); k++){
        matC.m_mat[i][j]+= matA.m_mat[i][k] * matB.m_mat[k][j];
      }
    }
  }
  return matC;
}

