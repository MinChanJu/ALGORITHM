#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int stack[N];
  int idx = 0;
  while (N--)
  {
    int op, X;
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      scanf("%d", &X);
      stack[idx++] = X;
      break;
    case 2:
      if (idx > 0)
        printf("%d\n", stack[--idx]);
      else
        printf("-1\n");
      break;
    case 3:
      printf("%d\n", idx);
      break;
    case 4:
      if (idx > 0)
        printf("0\n");
      else
        printf("1\n");
      break;
    case 5:
      if (idx > 0)
        printf("%d\n", stack[idx - 1]);
      else
        printf("-1\n");
      break;
    default:
      break;
    }
  }
}