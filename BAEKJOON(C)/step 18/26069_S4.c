#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1007

typedef struct Node
{
  char name[21];
  struct Node *next;
} Node;

Node *front, *back;

Node *createNode(char *name);
void push(char *name);
int search(char *name);
int count();

int main()
{
  int N;
  scanf("%d", &N);
  push("ChongChong");

  char A[21], B[21];
  while (N--)
  {
    scanf("%s %s", A, B);
    int as = search(A);
    int bs = search(B);
    if ((as == 1 && bs == 1) || (as == 0 && bs == 0)) continue;
    if (as == 1) push(B);
    if (bs == 1) push(A);
  }

  printf("%d\n", count());
}

Node *createNode(char *name)
{
  Node *new = (Node *)malloc(sizeof(Node));
  strcpy(new->name, name);
  new->next = NULL;
  return new;
}

void push(char *name)
{
  Node *new = createNode(name);
  if (front == NULL)
  {
    front = back = new;
  }
  else
  {
    back->next = new;
    back = new;
  }
}

int search(char *name)
{
  Node *cur = front;
  while (cur)
  {
    if (strcmp(name, cur->name) == 0)
      return 1;
    cur = cur->next;
  }
  return 0;
}

int count()
{
  int cnt = 0;
  while (front)
  {
    cnt++;
    front = front->next;
  }
  return cnt;
}