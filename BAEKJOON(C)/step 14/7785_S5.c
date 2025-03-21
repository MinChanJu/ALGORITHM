#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 697114

typedef struct
{
  char name[6];
  int company;
} Staff;

int compare(const void *a, const void *b)
{
  return strcmp(((Staff *)a)->name, ((Staff *)b)->name);
}

int find(Staff staffs[], char *key, int size)
{
  int s = 0, e = size - 1;
  while (s <= e)
  {
    int mid = (s + e) / 2;
    int cmp = strcmp(staffs[mid].name, key);
    if (cmp == 0)
      return mid;
    if (cmp < 0)
      s = mid + 1;
    if (cmp > 0)
      e = mid - 1;
  }
  return -1;
}

int main()
{
  Staff staffs[MAX_N];
  int size = 0;

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    char name[6], log[6];
    scanf("%s %s", name, log);
    int idx = find(staffs, name, size);
    if (idx != -1)
    {
      staffs[idx].company = strcmp(log, "enter") == 0 ? 1 : 0;
    }
    else
    {
      strcpy(staffs[size].name, name);
      staffs[size].company = strcmp(log, "enter") == 0 ? 1 : 0;
      size++;
      qsort(staffs, size, sizeof(Staff), compare);
    }
  }

  for (int i = size - 1; i >= 0; i--)
  {
    if (staffs[i].company == 1)
    {
      printf("%s\n", staffs[i].name);
    }
  }
}