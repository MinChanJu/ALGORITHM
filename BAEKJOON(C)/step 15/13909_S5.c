#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int cnt = 0;
  long k = 1;
  while (k <= N)
  {
    cnt++;
    k = (cnt+1)*(cnt+1);
  }
  
  printf("%d\n", cnt);
}