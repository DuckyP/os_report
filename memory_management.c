#include <stdio.h>
#include <stdlib.h>

int globalA = 1;
float globalB = 2.0;
char globalC = '3';

void callStack(int n){
  if(n == 0) return;
  int lv = n;
  printf("Level: %d, Address: %p\n", lv, &lv);
  callStack(n-1);
}

int main() {
  int *heapA = (int *)malloc(sizeof(int));
  float *heapB = (float *)malloc(sizeof(float));
  char *heapC = (char *)malloc(sizeof(char));

  printf("Address of stack variables:\n");
  callStack(5);
  printf("Address of heap variables:\n");
  printf("Heap A: %p\n", heapA);
  printf("Heap B: %p\n", heapB);
  printf("Heap C: %p\n", heapC);
  printf("Address of global variables:\n");
  printf("Global A: %p\n", &globalA);
  printf("Global B: %p\n", &globalB);
  printf("Global C: %p\n", &globalC);

  free(heapA);
  free(heapB);
  free(heapC);

  return 0;
}