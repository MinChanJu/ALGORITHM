#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  short num[10] = {0};
  while (N != 0)
  {
    num[N % 10]++;
    N /= 10;
  }
  for (int i = 9; i > -1; i--)
  {
    for (int j = 0; j < num[i]; j++)
    {
      printf("%d", i);
    }
  }

  printf("\n");
}