#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100003
#define NAME_LEN 21

typedef struct
{
  char name[NAME_LEN];
  int num;
  int used;
} Hash;

Hash table[MAX];

unsigned int hash(const char *str)
{
  unsigned int h = 5381;
  while (*str)
    h = ((h << 5) + h) + (unsigned char)(*str++);
  return h % MAX;
}

void insert(const char *name, int num)
{
  unsigned int h = hash(name);
  while (table[h].used)
  {
    if (strcmp(table[h].name, name) == 0)
      return;
    h = (h + 1) % MAX;
  }
  table[h].used = 1;
  strcpy(table[h].name, name);
  table[h].num = num;
}

int find(const char *name)
{
  unsigned int h = hash(name);
  while (table[h].used)
  {
    if (strcmp(table[h].name, name) == 0)
      return table[h].num;
    h = (h + 1) % MAX;
  }
  return -1;
}

int main()
{
  int N, M;
  scanf("%d %d", &N, &M);

  char name[NAME_LEN];
  char *monster[N];

  for (int i = 1; i <= N; i++)
  {
    scanf("%s", name);
    insert(name, i);
    monster[i] = strdup(name);
  }

  for (int i = 0; i < M; i++)
  {
    scanf("%s", name);
    if ('0' <= name[0] && name[0] <= '9')
    {
      int idx = atoi(name);
      printf("%s\n", monster[idx]);
    }
    else
    {
      printf("%d\n", find(name));
    }
  }

  return 0;
}