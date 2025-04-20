#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10007

typedef struct Node
{
  char word[11];
  int cnt;
  struct Node *next;
} Node;

Node *map[MAX];
Node *words[100000];
int size = 0;

int compare(const void *a, const void *b);
Node *createNode(char *word);
void push(char *word, int M);
void printArray();

int main()
{
  int N, M;
  scanf("%d %d", &N, &M);

  char word[11];
  for (int i = 0; i < N; i++)
  {
    scanf("%s", word);
    push(word, M);
  }

  qsort(words, size, sizeof(Node *), compare);
  printArray();
}

int compare(const void *a, const void *b)
{
  Node *A = *(Node **)a;
  Node *B = *(Node **)b;

  if (A->cnt != B->cnt)
    return B->cnt - A->cnt;
  if (strlen(A->word) != strlen(B->word))
    return strlen(B->word) - strlen(A->word);
  return strcmp(A->word, B->word);
}

Node *createNode(char *word)
{
  Node *new = (Node *)malloc(sizeof(Node));
  strcpy(new->word, word);
  new->cnt = 1;
  return new;
}

int hash(char *word)
{
  char *sub = strdup(word);
  unsigned int key = 107;
  while (*sub)
  {
    key = ((key << 5) + (*sub)) % MAX;
    sub++;
  }
  return key;
}

void push(char *word, int M)
{
  if (strlen(word) < M)
    return;

  int key = hash(word);
  if (map[key] == NULL)
  {
    map[key] = createNode(word);
    words[size++] = map[key];
  }
  else
  {
    Node *cur = map[key];

    while (cur)
    {
      if (strcmp(cur->word, word) == 0)
      {
        (cur->cnt)++;
        return;
      }
      if (cur->next == NULL)
        break;
      cur = cur->next;
    }

    cur->next = createNode(word);
    words[size++] = cur->next;
  }
}

void printArray()
{
  for (int i = 0; i < size; i++)
  {
    printf("%s\n", words[i]->word);
  }
}