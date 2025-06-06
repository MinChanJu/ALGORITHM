#include <stdio.h>
#include <math.h>

int isPrime(int n);

int main()
{
  int M, N;
  scanf("%d %d", &M, &N);

  for (int n = M; n <= N; n++)
  {
    if (isPrime(n)) printf("%d\n", n);
  }
  
}

int isPrime(int n)
{
  if (n < 2) return 0;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n%i == 0) return 0;
  }
  return 1;
}