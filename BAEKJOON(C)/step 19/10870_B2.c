#include <stdio.h>

int fibonacci(int n);

int main()
{
  int N;
  scanf("%d", &N);

  printf("%d\n", fibonacci(N));
}

int fibonacci(int n)
{
  if (n == 0 || n == 1)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}