#include <stdio.h>

int gcd(int A, int B);
int lcm(int A, int B);

int main()
{
  int A1, B1, A2, B2;
  scanf("%d %d\n%d %d", &A1, &B1, &A2, &B2);

  int g = gcd(B1, B2);
  int l = lcm(B1, B2);
  int A3 = (A1 * (l / B1)) + (A2 * (l / B2));
  int B3 = l;
  int ag = gcd(A3, B3);
  A3 /= ag;
  B3 /= ag;
  printf("%d %d\n", A3, B3);
}

int gcd(int A, int B)
{
  if (B == 0)
    return A;
  if (A == 0)
    return B;
  if (A > B)
    return gcd(B, A % B);
  return gcd(A, B % A);
}

int lcm(int A, int B)
{
  return (A * B) / gcd(A, B);
}