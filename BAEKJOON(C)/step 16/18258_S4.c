#include <stdio.h>
#include <string.h>

int main()
{
  int N;
  scanf("%d", &N);

  int queue[N];
  int front = 0, back = 0;

  for (int i = 0; i < N; i++)
  {
    char op[6];
    scanf("%s", op);
    if (strcmp(op, "push") == 0) {
      int X;
      scanf("%d", &X);
      queue[back++] = X;
    }
    else if (strcmp(op, "pop") == 0) {
      if (front == back) printf("-1\n");
      else printf("%d\n", queue[front++]);
    }
    else if (strcmp(op, "size") == 0) {
      printf("%d\n", back-front);
    }
    else if (strcmp(op, "empty") == 0) {
      if (front == back) printf("1\n");
      else printf("0\n");
    }
    else if (strcmp(op, "front") == 0) {
      if (front == back) printf("-1\n");
      else printf("%d\n", queue[front]);
    }
    else if (strcmp(op, "back") == 0) {
      if (front == back) printf("-1\n");
      else printf("%d\n", queue[back-1]);
    }
  }
}