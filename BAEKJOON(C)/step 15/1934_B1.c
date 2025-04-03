#include <stdio.h>

int gcd(int A, int B);
int lcm(int A, int B);

int main()
{
  int T;
  scanf("%d", &T);

  int answer[T];

  for (int i = 0; i < T; i++)
  {
    int A, B;
    scanf("%d %d", &A, &B);
    answer[i] = lcm(A, B);
  }

  for (int i = 0; i < T; i++)
  {
    printf("%d\n", answer[i]);
  }
}

int gcd(int A, int B)
{
  if (B == 0) return A;
  return gcd(B, A%B);
}

int lcm(int A, int B)
{
  if (A > B) return (A*B)/gcd(A, B);
  return (A*B)/gcd(B, A);
}