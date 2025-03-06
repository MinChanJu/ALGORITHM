#include <stdio.h>

typedef struct POS
{
  int x, y;
} POS;

void mergeSort(POS pos[], int s, int e);
int compare(POS a, POS b);

int main()
{
  int N;
  scanf("%d", &N);

  POS pos[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &pos[i].x, &pos[i].y);
  }

  mergeSort(pos, 0, N-1);

  for (int i = 0; i < N; i++)
  {
    printf("%d %d\n", pos[i].x, pos[i].y);
  }
}

void mergeSort(POS pos[], int s, int e)
{
  if (s == e)
    return;
  int mid = (s + e) / 2;
  mergeSort(pos, s, mid);
  mergeSort(pos, mid + 1, e);

  POS new[e - s + 1];
  int si = s, ei = mid + 1, ni = 0;
  while (si <= mid && ei <= e)
  {
    if (compare(pos[si], pos[ei]) < 0)
      new[ni++] = pos[si++];
    else
      new[ni++] = pos[ei++];
  }

  while (si <= mid) new[ni++] = pos[si++]; 
  while (ei <= e) new[ni++] = pos[ei++]; 
  
  for (int i = 0; i <= e-s; i++)
  {
    pos[s+i] = new[i];
  }
  
}

int compare(POS a, POS b)
{
  if (a.y != b.y)
    return a.y - b.y;
  else
    return a.x - b.x;
}