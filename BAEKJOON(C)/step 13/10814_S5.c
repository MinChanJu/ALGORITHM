#include <stdio.h>

typedef struct person
{
  int id;
  int age;
  char name[101];
} person;

void quickSort(person peo[], int s, int e);
int compare(person a, person b);

int main()
{
  int N;
  scanf("%d", &N);

  person peo[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d %s", &peo[i].age, peo[i].name);
    peo[i].id = i;
  }

  quickSort(peo, 0, N-1);

  for (int i = 0; i < N; i++)
  {
    printf("%d %s\n", peo[i].age, peo[i].name);
  }
}

void quickSort(person peo[], int s, int e)
{
  if (s >= e) return;

  int mid = (s + e) / 2;
  person pivot = peo[mid];

  person min[e-s], max[e-s];
  int ni = 0, xi = 0;
  for (int i = s; i <= e; i++)
  {
    if (compare(pivot, peo[i]) < 0) max[xi++] = peo[i];
    else if (compare(pivot, peo[i]) > 0) min[ni++] = peo[i];
  }

  for (int i = 0; i < ni; i++)
  {
    peo[i+s] = min[i];
  }
  peo[ni+s] = pivot;
  for (int i = 0; i < xi; i++)
  {
    peo[ni+s+i+1] = max[i];
  }

  quickSort(peo, s, ni+s-1);
  quickSort(peo, ni+s+1, e);
}

int compare(person a, person b)
{
  if (a.age != b.age) return a.age-b.age;
  return a.id-b.id;
}