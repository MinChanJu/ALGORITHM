#include <stdio.h>

void hanoi(int N, int a, int b, int c, int show);
int cnt = 0;

int main()
{
  int N;
  scanf("%d", &N);

  hanoi(N, 1, 2, 3, 0);
  printf("%d\n", cnt);
  hanoi(N, 1, 2, 3, 1);
}

void hanoi(int N, int a, int b, int c, int show)
{
  if (N == 0)
    return;
  hanoi(N - 1, a, c, b, show);
  cnt++;
  if (show)
    printf("%d %d\n", a, c);
  hanoi(N - 1, b, a, c, show);
}