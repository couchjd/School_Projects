#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "serial.h"
#include "parallel.h"
#include "matrix.h"

#define MIN 1
#define MAX 10

int cores = (int)sysconf(_SC_NPROCESSORS_ONLN);
int randRange(int, int);
void makeMats();

int main(){
  double serialTime;
  double parallelTime;
  makeMats();
  /*
  Matrix matA("matA.txt");
  Matrix matB("matB.txt");
  Matrix matC;
  */
  Matrix* matA = new Matrix("matA.txt");
  Matrix* matB = new Matrix("matB.txt");
  Matrix* matC;

  matA->m_mode = 0;
  serialTime = serial(matA, matB);
  parallelTime = parallel(matA, matB);
  printf("Serial completed in: %.2f ms\n", serialTime);
  printf("Parallel completed in: %.2f ms\n", parallelTime);
  return 0;
}

void makeMats(){
  FILE *fp;
  int rowA;
  int colArowB;
  int colB;
  int x, y;

  srand(time(NULL));
  rowA = randRange(MIN, MAX);
  colArowB = randRange(MIN, MAX);
  colB = randRange(MIN, MAX);

  fp = fopen("./matA.txt", "w+");
  fprintf(fp, "%d\n%d\n", rowA, colArowB);
  for(x = 0; x < rowA; x++){
    for(y = 0; y < colArowB; y++){
      fprintf(fp, "%d", randRange(MIN, MAX));
      if(y < colArowB - 1){
        fprintf(fp, "%c", ' ');
      }
    }
    fprintf(fp, "%c", '\n');
  }
  fclose(fp);

  fp = fopen("./matB.txt", "w+");
  fprintf(fp, "%d\n%d\n", colArowB, colB);
  for(x = 0; x < colArowB; x++){
    for(y = 0; y < colB; y++){
      fprintf(fp, "%d", randRange(MIN, MAX));
      if(y < colB - 1){
	fprintf(fp, "%c", ' ');
      }
    }
    fprintf(fp, "%c", '\n');
  }
  fclose(fp);
}

int randRange(int min, int max){
  return (((rand() + min) % max) + 1);
}
