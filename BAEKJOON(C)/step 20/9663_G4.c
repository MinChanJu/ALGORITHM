#include <stdio.h>
#include <stdlib.h>

void NQueen(int size);
int check(int pos);

int N, cnt = 0;
int *chess;

int main()
{
  scanf("%d", &N);
  chess = (int *)malloc(sizeof(int) * N);
  NQueen(0);
  printf("%d\n", cnt);
}

void NQueen(int size)
{
  if (size == N)
  {
    cnt++;
    return;
  }
  for (int i = 0; i < N; i++)
  {
    chess[size] = i;
    if (check(size))
      NQueen(size + 1);
  }
}

int check(int pos)
{
  for (int i = 0; i < pos; i++)
  {
    if (chess[pos] == chess[i] || (chess[pos] > chess[i] ? chess[pos] - chess[i] : chess[i] - chess[pos]) == (pos > i ? pos - i : i - pos))
      return 0;
  }
  return 1;
}

// #include <stdio.h>

// int main()
// {
//   int num[15] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596, 2279184};
//   int N;
//   scanf("%d", &N);
//   printf("%d\n", num[N - 1]);
// }