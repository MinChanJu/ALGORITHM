#include <stdio.h>

long long fact(int n);

int main()
{
  int N;
  scanf("%d", &N);

  printf("%lld\n", fact(N));
}

long long fact(int n)
{
  if (n == 0)
    return 1;
  return n * fact(n - 1);
}