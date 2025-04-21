#include <stdio.h>

void back(int A[], int size, int s);

int N, M;

int main()
{
  scanf("%d %d", &N, &M);
  int A[M];
  back(A, 0, 1);
}

void back(int A[], int size, int s)
{
  if (size == M)
  {
    for (int i = 0; i < size; i++)
    {
      printf("%d", A[i]);
      if (i == size-1) printf("\n");
      else printf(" ");
    }
    return;
  }
  for (int i = s; i <= N; i++)
  {
    A[size] = i;
    back(A, size + 1, i + 1);
  }
}