#include <stdio.h>

void mergeSort(int A[][2], int s, int e);
int compare(int *a, int *b);

int main()
{
  int N;
  scanf("%d", &N);

  int pos[N][2];
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &pos[i][0], &pos[i][1]);
  }

  mergeSort(pos, 0, N - 1);

  for (int i = 0; i < N; i++)
  {
    printf("%d %d\n", pos[i][0], pos[i][1]);
  }
}

void mergeSort(int A[][2], int s, int e)
{
  if (s == e)
    return;
  int mid = (e + s) / 2;
  mergeSort(A, s, mid);
  mergeSort(A, mid + 1, e);

  int new[e - s + 1][2];
  int si = s, ei = mid + 1, ni = 0;
  while (si <= mid && ei <= e)
  {
    if (compare(A[si], A[ei]) < 0)
    {
      new[ni][0] = A[si][0];
      new[ni][1] = A[si][1];
      ni++;
      si++;
    }
    else
    {
      new[ni][0] = A[ei][0];
      new[ni][1] = A[ei][1];
      ni++;
      ei++;
    }
  }

  while (si <= mid)
  {
    new[ni][0] = A[si][0];
    new[ni][1] = A[si][1];
    ni++;
    si++;
  }

  while (ei <= e)
  {
    new[ni][0] = A[ei][0];
    new[ni][1] = A[ei][1];
    ni++;
    ei++;
  }

  for (int i = 0; i <= e-s; i++)
  {
    A[s+i][0] = new[i][0];
    A[s+i][1] = new[i][1];
  }
  
}

int compare(int *a, int *b)
{
  if (a[0] != b[0])
    return a[0] - b[0];
  else
    return a[1] - b[1];
}