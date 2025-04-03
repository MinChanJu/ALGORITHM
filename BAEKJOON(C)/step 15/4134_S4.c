#include <stdio.h>
#include <math.h>

int isPrime(long a);

int main()
{
  int T;
  scanf("%d", &T);

  while (T--)
  {
    long n;
    scanf("%ld", &n);

    while (1)
    {
      if (isPrime(n))
      {
        printf("%ld\n", n);
        break;
      }
      n++;
    }
  }
}

int isPrime(long a)
{
  if (a < 2) return 0;
  for (int i = 2; i <= sqrt(a); i++)
  {
    if (a % i == 0)
      return 0;
  }
  return 1;
}