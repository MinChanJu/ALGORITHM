#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return strcmp((char*) a, (char*) b);
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  char name[21];
  char listen[N][21], watch[M][21];

  for (int i = 0; i < N; i++) {
    scanf("%s", name);
    strcpy(listen[i], name);
  }
  for (int i = 0; i < M; i++) {
    scanf("%s", name);
    strcpy(watch[i], name);
  }

  qsort(listen, N, sizeof(char)*21, compare);
  qsort(watch, M, sizeof(char)*21, compare);

  int len = 0;
  int idx_l = 0, idx_w = 0;
  while (idx_l < N && idx_w < M)
  {
    int key = strcmp(listen[idx_l], watch[idx_w]);
    if (key == 0) {
      len++;
      idx_l++;
      idx_w++;
    }
    else if (key > 0) idx_w++;
    else idx_l++;
  }

  printf("%d\n", len);
  idx_l = idx_w = 0;
  while (idx_l < N && idx_w < M)
  {
    int key = strcmp(listen[idx_l], watch[idx_w]);
    if (key == 0) {
      printf("%s\n", listen[idx_l]);
      idx_l++;
      idx_w++;
    }
    else if (key > 0) idx_w++;
    else idx_l++;
  }
}