#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  int num[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &num[i]);

  int sum = 0, max = num[0];
  for (int i = 0; i < n; i++)
  {
    sum += num[i];
    if (sum > max)
      max = sum;
    if (sum < 0)
      sum = 0;
  }

  printf("%d\n", max);
}