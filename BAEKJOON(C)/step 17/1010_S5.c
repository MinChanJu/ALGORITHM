#include <stdio.h>

long long comb(int N, int K);

int main()
{
  int TC;
  scanf("%d", &TC);

  while (TC--)
  {
    int N, M;
    scanf("%d %d", &N, &M);
    printf("%lld\n", comb(M, N));
  }
}

long long comb(int n, int r)
{
  if (r > n - r)
    r = n - r;

  long long res = 1;
  for (int i = 1; i <= r; i++)
  {
    res *= n - i + 1;
    res /= i;
  }
  return res;
}