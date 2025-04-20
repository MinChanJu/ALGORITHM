#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *createCanto(int N);
void canto(int *A, int s, int e);
void printCanto(int *A, int size);

int main()
{
  int N;
  while (scanf("%d", &N) != EOF)
  {
    int size = pow(3, N);
    int *A = createCanto(size);
    canto(A, 0, size - 1);
    printCanto(A, size);
  }
}

int *createCanto(int size)
{
  int *A = (int *)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++)
  {
    A[i] = '-';
  }

  return A;
}

void canto(int *A, int s, int e)
{
  if (s >= e) return;
  int m = (e - s + 1) / 3;
  canto(A, s, s + m - 1);
  canto(A, e + 1 - m, e);
  for (int i = s + m; i <= e - m; i++)
  {
    A[i] = ' ';
  }
}

void printCanto(int *A, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%c", A[i]);
  }
  printf("\n");
}