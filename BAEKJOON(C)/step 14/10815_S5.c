#include <stdio.h>

void mergeSort(int num[], int s, int e);
int find(int num[], int size, int key);

int main()
{
  int N;
  scanf("%d", &N);

  int num[N];
  for (int i = 0; i < N; i++)
    scanf("%d", &num[i]);

  int M;
  scanf("%d", &M);

  int check[M];
  for (int i = 0; i < M; i++)
    scanf("%d", &check[i]);

  mergeSort(num, 0, N - 1);

  for (int i = 0; i < M; i++)
    printf("%d ", find(num, N, check[i]));
  printf("\n");
}

void mergeSort(int num[], int s, int e)
{
  if (s >= e)
    return;
  int mid = (s + e) / 2;
  mergeSort(num, s, mid);
  mergeSort(num, mid + 1, e);

  int new[e - s + 1];
  int si = s, ei = mid + 1, ni = 0;

  while (si <= mid && ei <= e)
  {
    if (num[si] < num[ei])
      new[ni++] = num[si++];
    else
      new[ni++] = num[ei++];
  }

  while (si <= mid)
    new[ni++] = num[si++];
  while (ei <= e)
    new[ni++] = num[ei++];

  for (int i = 0; i <= e - s; i++)
    num[i + s] = new[i];
}

int find(int num[], int size, int key)
{
  int s = 0, e = size - 1;
  while (s <= e)
  {
    int mid = (s + e) / 2;
    if (num[mid] == key)
      return 1;
    else if (num[mid] < key)
      s = mid + 1;
    else if (num[mid] > key)
      e = mid - 1;
  }
  return 0;
}