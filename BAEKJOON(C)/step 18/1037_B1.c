#include <stdio.h>

int main()
{
  int num;
  scanf("%d", &num);

  int divisor[num];
  for (int i = 0; i < num; i++)
  {
    scanf("%d", &divisor[i]);
  }

  int min = divisor[0], max = divisor[0];
  for (int i = 0; i < num; i++)
  {
    if (divisor[i] < min)
      min = divisor[i];
    if (divisor[i] > max)
      max = divisor[i];
  }

  printf("%d\n", min * max);
}