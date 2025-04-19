#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int s = 1;
  for (int i = 0; i < N; i++)
  {
    s *= 2;
  }
  
  printf("%d\n", s);
}