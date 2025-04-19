#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int num, data;
  struct Node *next, *prev;
} Node;

Node *createNode(int num, int data);
void push(Node **front, Node **back, int num, int data);
Node *pop(Node **front, Node **back);
void moveLeft(Node **front, Node **back);
void moveRight(Node **front, Node **back);

int main()
{
  int N, x;
  scanf("%d", &N);

  Node *front = NULL, *back = NULL;
  for (int i = 1; i <= N; i++)
  {
    scanf("%d", &x);
    push(&front, &back, i, x);
  }

  while (1)
  {
    Node *tmp = pop(&front, &back);

    printf("%d ", tmp->num);
    int rotate = tmp->data;
    free(tmp);

    if (front == NULL)
      break;

    if (rotate > 0)
    {
      for (int i = 1; i < rotate; i++)
        moveRight(&front, &back);
    }
    else
    {
      for (int i = 0; i > rotate; i--)
        moveLeft(&front, &back);
    }
  }

  printf("\n");
  return 0;
}

Node *createNode(int num, int data)
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->num = num;
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void push(Node **front, Node **back, int num, int data)
{
  Node *new = createNode(num, data);
  if (*front == NULL)
  {
    *front = *back = new;
  }
  else
  {
    (*back)->next = new;
    new->prev = *back;
    *back = new;
  }
}

Node *pop(Node **front, Node **back)
{
  Node *tmp = *front;
  *front = (*front)->next;
  if (*front != NULL)
    (*front)->prev = NULL;
  else
    *back = NULL;
  return tmp;
}

void moveLeft(Node **front, Node **back)
{
  (*front)->prev = *back;
  (*back)->next = *front;

  *front = (*front)->prev;
  *back = (*back)->prev;

  (*front)->prev = NULL;
  (*back)->next = NULL;
}

void moveRight(Node **front, Node **back)
{
  (*back)->next = *front;
  (*front)->prev = *back;

  *front = (*front)->next;
  *back = (*back)->next;

  (*front)->prev = NULL;
  (*back)->next = NULL;
}