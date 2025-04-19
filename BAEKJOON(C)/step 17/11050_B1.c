#include <stdio.h>

int fact(int n);

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);

  printf("%d\n", fact(N) / fact(N - K) / fact(K));
}

int fact(int n)
{
  int s = 1;
  for (int i = 1; i <= n; i++)
  {
    s *= i;
  }
  return s;
}