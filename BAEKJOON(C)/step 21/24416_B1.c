#include <stdio.h>

int fib(int n);

int cnt = 1;

int main()
{
  int n;
  scanf("%d", &n);
  fib(n);
  printf("%d %d\n", cnt, n - 2);
  return 0;
}

int fib(int n)
{
  if (n == 1 || n == 2)
    return 1;
  cnt++;
  return (fib(n - 1) + fib(n - 2));
}