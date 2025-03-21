#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10000

typedef struct Node
{
  char key[501];
  int value;
  struct Node *next;
} Node;

typedef struct
{
  Node *buckets[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *key);
void initTable(HashTable *table);
void insert(HashTable *table, const char *key, int value);
int search(HashTable *table, const char *key);
void freeTable(HashTable *table);

int main()
{
  HashTable table;
  initTable(&table);
  char text[501];

  int N, M;
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++)
  {
    scanf("%s", text);
    insert(&table, text, 10);
  }

  int cnt = 0;
  for (int i = 0; i < M; i++)
  {
    scanf("%s", text);
    if (search(&table, text))
    {
      cnt++;
    }
  }
  printf("%d\n", cnt);

  freeTable(&table);
}

unsigned int hash(const char *key)
{
  unsigned int hash = 0;
  while (*key)
  {
    hash = (hash * 31) + (*key++);
  }
  return hash % TABLE_SIZE;
}

void initTable(HashTable *table)
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    table->buckets[i] = NULL;
  }
}

void insert(HashTable *table, const char *key, int value)
{
  unsigned int index = hash(key);
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->key, key);
  newNode->value = value;
  newNode->next = table->buckets[index];
  table->buckets[index] = newNode;
}

int search(HashTable *table, const char *key)
{
  unsigned int index = hash(key);
  Node *current = table->buckets[index];
  while (current)
  {
    if (strcmp(current->key, key) == 0)
    {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void freeTable(HashTable *table)
{
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    Node *current = table->buckets[i];
    while (current)
    {
      Node *temp = current;
      current = current->next;
      free(temp);
    }
  }
}