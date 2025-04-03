#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main()
{
  int N, M;
  scanf("%d %d", &N, &M);

  int A[N], B[M];
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);
  for (int i = 0; i < M; i++)
    scanf("%d", &B[i]);

  qsort(A, N, sizeof(int), compare);
  qsort(B, M, sizeof(int), compare);

  int ai = 0, bi = 0, cnt = 0;
  while (ai < N && bi < M)
  {
    if (A[ai] == B[bi])
    {
      ai++;
      bi++;
    }
    else if (A[ai] < B[bi])
    {
      cnt++;
      ai++;
    }
    else
    {
      cnt++;
      bi++;
    }
  }
  cnt += (N - ai) + (M - bi);

  printf("%d\n", cnt);
  return 0;
}

int compare(const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}