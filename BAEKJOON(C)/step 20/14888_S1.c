#include <stdio.h>
#include <stdlib.h>

void dfs(int idx, int result);

int N, *A, operation[4];
int max = -1000000000, min = 1000000000;

int main()
{
  scanf("%d", &N);

  A = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    scanf("%d", &A[i]);

  for (int i = 0; i < 4; i++)
    scanf("%d", &operation[i]);

  dfs(1, A[0]);
  printf("%d\n%d\n", max, min);
}

void dfs(int idx, int result)
{
  if (idx == N)
  {
    if (max < result)
      max = result;
    if (min > result)
      min = result;
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (operation[i] > 0)
    {
      operation[i]--;
      if (i == 0)
        dfs(idx + 1, result + A[idx]);
      if (i == 1)
        dfs(idx + 1, result - A[idx]);
      if (i == 2)
        dfs(idx + 1, result * A[idx]);
      if (i == 3)
        dfs(idx + 1, result / A[idx]);
      operation[i]++;
    }
  }
}