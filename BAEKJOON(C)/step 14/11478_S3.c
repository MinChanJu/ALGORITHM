#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Trie
{
  struct Trie* next[26];
  int isEnd;
} Trie;

Trie* newNode();
int insert(Trie* root, char* str, int s, int e);

int main() {
  char S[1001];
  scanf("%s", S);

  Trie *root = newNode();
  int cnt = 0;

  int N = strlen(S);
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      cnt += insert(root, S, i, j);
    }
  }

  printf("%d\n", cnt);
  return 0;
}

Trie* newNode()
{
  Trie* new = (Trie*)malloc(sizeof(Trie));
  for (int i = 0; i < 26; i++) new->next[i] = NULL;
  new->isEnd = 0;
  return new;
}

int insert(Trie* root, char* str, int s, int e)
{
  Trie* cur = root;
  int isNew = 0;
  for (int i = s; i <= e; i++)
  {
    int idx = str[i]-'a';
    if (cur->next[idx] == NULL)
    {
      cur->next[idx] = newNode();
      isNew = 1;
    }
    cur = cur->next[idx];
  }

  if (!cur->isEnd){
    cur->isEnd = 1;
    isNew = 1;
  }
  
  return isNew;
}