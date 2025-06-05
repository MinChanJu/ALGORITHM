#include <stdio.h>

int count[20000001];

int main() {
  int N, M, num;

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &num);
    count[num+10000000]++;
  }
  
  scanf("%d", &M);
  for (int i = 0; i < M; i++)
  {
    scanf("%d", &num);
    printf("%d ", count[num+10000000]);
  }
  printf("\n");
}