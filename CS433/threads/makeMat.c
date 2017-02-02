#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MIN 1
#define MAX 10

int randRange(int, int);

void makeMatrices(){
  FILE *fp;
  char row[256];
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
