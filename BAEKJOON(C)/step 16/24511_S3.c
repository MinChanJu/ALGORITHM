#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *prev, *next;
} Node;

Node *createNode(int data);
void push(Node **front, Node **back, int data);
void pushLeft(Node **front, Node **back, int data);
int pop(Node **front, Node **back);

int main()
{
  int N;
  scanf("%d", &N);

  int A[N], B[N];

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &B[i]);
  }

  int M;
  scanf("%d", &M);

  int C[M];

  for (int i = 0; i < M; i++)
  {
    scanf("%d", &C[i]);
  }

  Node *front = NULL, *back = NULL;

  for (int i = 0; i < N; i++)
  {
    if (A[i] == 0) {
      push(&front, &back, B[i]);
    }
  }
  

  for (int i = 0; i < M; i++)
  {
    pushLeft(&front, &back, C[i]);
    printf("%d ", pop(&front, &back));
  }

  printf("\n");
  return 0;
}

Node *createNode(int data)
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

void push(Node **front, Node **back, int data)
{
  Node *new = createNode(data);
  if (*front == NULL)
  {
    *front = *back = new;
  }
  else
  {
    (*back)->next = new;
    new->prev = *back;
    *back = (*back)->next;
  }
}

void pushLeft(Node **front, Node **back, int data)
{
  Node *new = createNode(data);
  if (*front == NULL)
  {
    *front = *back = new;
  }
  else
  {
    (*front)->prev = new;
    new->next = *front;
    *front = (*front)->prev;
  }
}

int pop(Node **front, Node **back)
{
  if (back == NULL)
    return -1;

  Node *tmp = *back;
  *back = (*back)->prev;

  if (*back != NULL)
    (*back)->next = NULL;
  else
    *front = NULL;

  int data = tmp->data;
  free(tmp);

  return data;
}