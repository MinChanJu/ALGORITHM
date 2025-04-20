#include <stdio.h>

int N, M;

void back(int A[], int size);

int main()
{
  scanf("%d %d", &N, &M);

  int A[M];
  back(A, 0);
}

void back(int A[], int size)
{
  if (size == M)
  {
    for (int i = 0; i < M; i++)
    {
      printf("%d ", A[i]);
    }
    printf("\n");
    return;
  }

  for (int i = 1; i <= N; i++)
  {
    int check = 0;
    for (int j = 0; j < size; j++)
    {
      if (A[j] == i)
      {
        check = 1;
        break;
      }
    }
    if (check) continue;
    A[size] = i;
    back(A, size+1);
  }
}