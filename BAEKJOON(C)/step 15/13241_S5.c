#include <stdio.h>

int gcd(int A, int B);
long long int lcm(int A, int B);

int main()
{
  int A, B;
  scanf("%d %d", &A, &B);
  printf("%lld\n", lcm(A, B));
}

int gcd(int A, int B)
{
  if (B == 0)
    return A;
  return gcd(B, A % B);
}

long long int lcm(int A, int B)
{
  if (A > B)
    return ((long long int)A * B) / gcd(A, B);
  return ((long long int)A * B) / gcd(B, A);
}