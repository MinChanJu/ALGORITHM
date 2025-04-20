#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1007

typedef struct Node
{
  char name[21];
  struct Node *next;
} Node;

Node *map[MAX];

Node *createNode(char *name);
unsigned int hash(char *name);
int push(char *name);
void clear();

int main()
{
  int N, cnt = 0;
  scanf("%d", &N);

  char S[21];
  while (N--)
  {
    scanf("%s", S);
    if (strcmp(S, "ENTER") == 0)
      clear();
    else
      cnt += push(S);
  }

  printf("%d\n", cnt);
}

Node *createNode(char *name)
{
  Node *new = (Node *)malloc(sizeof(Node));
  strcpy(new->name, name);
  new->next = NULL;
  return new;
}

unsigned int hash(char *name)
{
  char *dup = strdup(name);
  unsigned int key = 0;
  while (*dup)
  {
    key = ((key << 5) + (*dup)) % MAX;
    dup++;
  }
  return key;
}

int push(char *name)
{
  int key = hash(name);
  if (map[key] == NULL)
  {
    map[key] = createNode(name);
  }
  else
  {
    Node *cur = map[key];

    while (1)
    {
      if (strcmp(cur->name, name) == 0)
        return 0;
      if (cur->next == NULL)
        break;
      cur = cur->next;
    }

    cur->next = createNode(name);
  }
  return 1;
}

void clear()
{
  for (int i = 0; i < MAX; i++)
  {
    Node *cur = map[i];
    while (cur)
    {
      Node *tmp = cur;
      cur = cur->next;
      free(tmp);
    }
    map[i] = NULL;
  }
}