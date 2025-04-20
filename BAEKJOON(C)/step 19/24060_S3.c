#include <stdio.h>

void merge_sort(int A[], int p, int r, int K);
void merge(int A[], int p, int q, int r, int K);

int cnt = 0;
int answer = -1;

int main()
{
  int N, K;
  scanf("%d %d", &N, &K);

  int A[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
  }

  merge_sort(A, 0, N - 1, K);
  printf("%d\n", answer);
}

void merge_sort(int A[], int p, int r, int K)
{
  if (p < r)
  {
    int q = (p + r) / 2;
    merge_sort(A, p, q, K);
    merge_sort(A, q + 1, r, K);
    merge(A, p, q, r, K);
  }
}

void merge(int A[], int p, int q, int r, int K)
{
  int i = p, j = q + 1, t = 1;
  int tmp[r - p + 1];
  while (i <= q && j <= r)
  {
    if (A[i] <= A[j])
      tmp[t++] = A[i++];
    else
      tmp[t++] = A[j++];
  }
  while (i <= q)
    tmp[t++] = A[i++];
  while (j <= r)
    tmp[t++] = A[j++];
  i = p;
  t = 1;
  while (i <= r)
  {
    A[i++] = tmp[t++];
    cnt++;
    if (cnt == K)
      answer = A[i - 1];
  }
}