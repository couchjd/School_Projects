#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

const Matrix* matA;
const Matrix* matB;
Matrix* matC;

struct v {
 int i; /* row */
 int j; /* column */
};

struct timeval parallelT1, parallelT2;
double parallelTime;

void *mult(void *param); /* the thread */

double parallel(const Matrix* A, const Matrix* B) {
  matA = A;
  matB = B;
  gettimeofday(&parallelT1, NULL);

  matC = new Matrix(matA->getRows(), matB->getCols());
  printf("CALCULATING PARALLEL:\n");

  int i,j;
  for(i = 0; i < matA->getRows(); i++) {
    for(j = 0; j < matB->getCols(); j++) {
     //Assign a row and column for each thread
     struct v *data = (struct v *) malloc(sizeof(struct v));
     data->i = i;
     data->j = j;
     /* Now create the thread passing it data as a parameter */
     pthread_t tid;       //Thread ID
     pthread_attr_t attr; //Set of thread attributes
     pthread_attr_init(&attr);
     pthread_create(&tid,&attr,mult,data);
     pthread_join(tid, NULL);
    }
  }

  matC->printMat();
  gettimeofday(&parallelT2, NULL);
  parallelTime = (parallelT2.tv_sec - parallelT1.tv_sec) * 1000.0;      // sec to ms
  parallelTime += (parallelT2.tv_usec - parallelT1.tv_usec) / 1000.0;   // us to ms
  return parallelTime;
}

void *mult(void *param) {
  struct v *data = (v*)param; // the structure that holds our data
  int n;
  int sum = 0; //the counter and sum

  for(n = 0; n < matA->getCols(); n++){
    sum += matA->m_mat[data->i][n] * matB->m_mat[n][data->j];
  }
  matC->m_mat[data->i][data->j] = sum;
  pthread_exit(0);
}
