#include <stdio.h>

int main()
{
  int K;
  scanf("%d", &K);

  int num[K];
  int idx = 0;
  for (int i = 0; i < K; i++)
  {
    int x;
    scanf("%d", &x);
    if (x == 0)
      idx--;
    else
      num[idx++] = x;
  }

  int sub = 0;
  for (int i = 0; i < idx; i++)
  {
    sub += num[i];
  }

  printf("%d\n", sub);
}