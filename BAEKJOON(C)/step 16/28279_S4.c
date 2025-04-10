#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node *prev;
  int num;
  struct Node *next;
} Node;

void push(Node **front, Node **back, int num, int *size);
void pushleft(Node **front, Node **back, int num, int *size);
int pop(Node **front, Node **back, int *size);
int popleft(Node **front, Node **back, int *size);

int main()
{
  int N;
  scanf("%d", &N);

  Node *front, *back;
  int answer[N];
  int op, X, idx = 0, size = 0;
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &op);
    if (op == 1)
    {
      scanf("%d", &X);
      pushleft(&front, &back, X, &size);
    }
    if (op == 2)
    {
      scanf("%d", &X);
      push(&front, &back, X, &size);
    }
    if (op == 3)
      answer[idx++] = popleft(&front, &back, &size);
    if (op == 4)
      answer[idx++] = pop(&front, &back, &size);
    if (op == 5)
      answer[idx++] = size;
    if (op == 6)
      answer[idx++] = size > 0 ? 0 : 1;
    if (op == 7)
      answer[idx++] = size > 0 ? front->num : -1;
    if (op == 8)
      answer[idx++] = size > 0 ? back->num : -1;
  }

  for (int i = 0; i < idx; i++)
  {
    printf("%d\n", answer[i]);
  }
  
}

void push(Node **front, Node **back, int num, int *size)
{
  Node *prev = NULL;
  if (*size == 0)
  {
    *back = (Node *)malloc(sizeof(Node));
  }
  else
  {
    prev = *back;
    (*back)->next = (Node *)malloc(sizeof(Node));
    *back = (*back)->next;
  }
  (*back)->num = num;
  (*back)->prev = prev;
  (*back)->next = NULL;
  if (*size == 0)
  {
    *front = *back;
  }
  (*size)++;
  return;
}

void pushleft(Node **front, Node **back, int num, int *size)
{
  Node *next = NULL;
  if (*size == 0)
  {
    *front = (Node *)malloc(sizeof(Node));
  }
  else
  {
    next = *front;
    (*front)->prev = (Node *)malloc(sizeof(Node));
    *front = (*front)->prev;
  }
  (*front)->num = num;
  (*front)->prev = NULL;
  (*front)->next = next;
  if (*size == 0)
  {
    *back = *front;
  }
  (*size)++;
  return;
}

int pop(Node **front, Node **back, int *size)
{
  if (*size == 0)
  {
    return -1;
  }
  int tmp = (*back)->num;
  Node* prev = *back;
  *back = (*back)->prev;
  free(prev);

  (*size)--;
  return tmp;
}

int popleft(Node **front, Node **back, int *size)
{
  if (*size == 0)
  {
    return -1;
  }
  int tmp = (*front)->num;
  Node* prev = *front;
  *front = (*front)->next;
  free(prev);

  (*size)--;
  return tmp;
}