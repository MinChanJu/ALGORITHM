#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int s = 1;
  for (int i = 1; i <= N; i++)
  {
    s *= i;
  }
  
  printf("%d\n", s);
}