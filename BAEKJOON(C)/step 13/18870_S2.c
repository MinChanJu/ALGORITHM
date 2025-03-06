#include <stdio.h>
#include <stdlib.h>

void mergeSort(int X[], int s, int e);
int *set(int X[], int size);
int find(int *seq, int key);

int main()
{
  int N;
  scanf("%d", &N);

  int X[N];
  int copy[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &X[i]);
    copy[i] = X[i];
  }

  mergeSort(copy, 0, N - 1);
  int *seq = set(copy, N);
  for (int i = 0; i < N; i++)
  {
    printf("%d ", find(seq, X[i]));
  }
  printf("\n");
}

void mergeSort(int X[], int s, int e)
{
  if (s >= e)
    return;
  int mid = (s + e) / 2;
  mergeSort(X, s, mid);
  mergeSort(X, mid + 1, e);

  int new[e - s + 1];
  int si = s, ei = mid + 1, ni = 0;

  while (si <= mid && ei <= e)
  {
    if (X[si] < X[ei])
      new[ni++] = X[si++];
    else
      new[ni++] = X[ei++];
  }

  while (si <= mid)
    new[ni++] = X[si++];
  while (ei <= e)
    new[ni++] = X[ei++];

  for (int i = 0; i <= e - s; i++)
  {
    X[i + s] = new[i];
  }
}

int *set(int X[], int size)
{
  int last = X[0];
  int cnt = 1;
  for (int i = 1; i < size; i++)
  {
    if (last != X[i])
      cnt++;
    last = X[i];
  }

  int *seq = malloc((cnt + 1) * sizeof(int));
  int si = 2;
  last = X[0];
  seq[0] = cnt;
  seq[1] = X[0];
  for (int i = 1; i < size; i++)
  {
    if (last != X[i])
      seq[si++] = X[i];
    last = X[i];
  }

  return seq;
}

int find(int *seq, int key)
{
  int s = 1, e = seq[0];
  while (s <= e)
  {
    int mid = (s + e) / 2;
    if (seq[mid] == key)
      return mid - 1;
    else if (seq[mid] < key)
      s = mid + 1;
    else if (seq[mid] > key)
      e = mid - 1;
  }
  return -1;
}