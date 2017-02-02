#include "matrix.h"
#include <stdlib.h>

int main(){
  int* matrixA;
  int* matrixB;
  int* prodMatrix;
  int rowsA;
  int colsA;
  int rowsB;
  int colsB;

  makeMatrix("./matA.txt", &matrixA, &rowsA, &colsA);

  int i;
  int j;
  printf("###### PRINT MATRIX A ######\n");
  for(i = 0; i < rowsA; i++){
    for(j = 0; j < colsA; j++){
      printf("%d", matrixA[i]);
      if(j < colsA){
	printf("%c", ' ');
      }
    }
    printf("%c", '\n');
  }

  makeMatrix("./matB.txt", &matrixB, &rowsB, &colsB);

  matMult(&matrixA, &matrixB, &prodMatrix, rowsA, colsA, rowsB, colsB);

  return 0;
}

void makeMatrix(char* fileName, int** matrix, int* rows, int* cols){
  char* line;
  FILE* fp;
  size_t len = 0;
  //int rows = 0;
  //int cols = 0;
  int num;

  fp = fopen(fileName, "r");
  getline(&line, &len, fp);
  *rows = atoi(line);
  getline(&line, &len, fp);
  *cols = atoi(line);

  //  printf("%d\n%d\n", *rows, *cols);
  int x = 0;
  int y = 0;
  int newMat[*rows][*cols];

  for(x = 0; x < *rows; x++){
    for(y = 0; y < *cols; y++){
      fscanf(fp, "%d", &num);
      newMat[x][y] = num;
      //printf("%d", num);
      if(y < *cols){
	//printf("%c", ' ');
      }
    }
    //printf("%c", '\n');
  }
  int i;
  int j;

  for(i = 0; i < *rows; i++){
    for(j = 0; j < *cols; j++){
      printf("%d", (int)newMat[i][j]);
      if(j < *cols){
	printf("%c", ' ');
      }
    }
    printf("%c", '\n');
  }
}


void matMult(int** matA, int** matB, int** matRet, int rowsA, int colsA, int rowsB, int colsB){
  int i;
  int j;
  int k;

  //printf("%p %p %p %d %d %d %d\n", matA, matB, matRet, rowsA, colsA, rowsB, colsB);
  //printf("%d %d\n", matA[0][0], matB[0][0]);
  printf("###### IN MULT ######\n");
  for(i = 0; i < rowsA; i++){
    for(j = 0; j < colsA; j++){
      printf("%d", matA[i][j]);
      if(j < colsA){
	printf("%c", ' ');
      }
    }
    printf("%c", '\n');
  }

}
