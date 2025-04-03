#include <stdio.h>

int gcd(int A, int B);

int main()
{
  int N;
  scanf("%d", &N);

  int tree[N];
  for (int i = 0; i < N; i++)
    scanf("%d", &tree[i]);
  int g = tree[1]-tree[0];
  for (int i = 1; i < N-1; i++)
  {
    g = gcd(g, tree[i+1]-tree[i]);
  }

  int cnt = 0;
  int i = 1;
  int k = tree[0];
  while (k < tree[N-1])
  {
    if (k + g == tree[i]) i++;
    else cnt++;
    k += g;
  }

  printf("%d\n", cnt);
  return 0;
}

int gcd(int A, int B)
{
  if (B == 0) return A;
  if (A == 0) return B;
  if (A > B) return gcd(B, A%B);
  return gcd(A, B%A);
}