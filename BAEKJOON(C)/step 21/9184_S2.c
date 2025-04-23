#include <stdio.h>

int w(int a, int b, int c);

int memo[101][101][101];

int main()
{
  int a, b, c;

  while (1)
  {
    scanf("%d %d %d", &a, &b, &c);
    if (a == -1 && b == -1 && c == -1)
      break;
    int result = w(a, b, c);
    printf("w(%d, %d, %d) = %d\n", a, b, c, result);
  }

  return 0;
}

int w(int a, int b, int c)
{
  if (memo[a + 50][b + 50][c + 50] != 0)
    return memo[a + 50][b + 50][c + 50];
  
  if (a <= 0 || b <= 0 || c <= 0)
  {
    memo[a + 50][b + 50][c + 50] = 1;
    return memo[a + 50][b + 50][c + 50];
  }

  if (a > 20 || b > 20 || c > 20)
  {
    memo[a + 50][b + 50][c + 50] = w(20, 20, 20);
    return memo[a + 50][b + 50][c + 50];
  }

  if (a < b && b < c)
  {
    memo[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return memo[a + 50][b + 50][c + 50];
  }

  memo[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return memo[a + 50][b + 50][c + 50];
}