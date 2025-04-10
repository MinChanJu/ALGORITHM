#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int num;
  struct Node *next;
} Node;

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);

  Node *front = (Node *)malloc(sizeof(Node));
  front->num = 1;
  front->next = NULL;
  Node *back = front;
  for (int i = 2; i <= N; i++)
  {
    back->next = (Node *)malloc(sizeof(Node));
    back = back->next;
    back->num = i;
    back->next = NULL;
  }

  printf("<");
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j < K; j++)
    {
      back->next = front;
      back = back->next;
      front = front->next;
    }

    Node *prev = front;
    front = front->next;
    printf("%d", prev->num);
    if (i < N)
    {
      printf(", ");
    }
    free(prev);
  }
  printf(">\n");
}