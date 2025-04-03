#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char enter[1000000][6];
char leave[1000000][6];

int compare(const void *a, const void *b)
{
  return strcmp((char*) b, (char*) a);
}

int main()
{
  int n, idx_e = 0, idx_l = 0;
  char name[6], action[6];

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    scanf("%s %s", name, action);
    if (strcmp(action, "enter") == 0)
      strcpy(enter[idx_e++], name);
    if (strcmp(action, "leave") == 0)
      strcpy(leave[idx_l++], name);
  }

  qsort(enter, idx_e, sizeof(char) * 6, compare);
  qsort(leave, idx_l, sizeof(char) * 6, compare);

  int idx_ei = 0, idx_li = 0;
  while (idx_ei < idx_e && idx_li < idx_l)
  {
    if (strcmp(enter[idx_ei], leave[idx_li]) == 0)
    {
      idx_ei++;
      idx_li++;
    }
    else
    {
      printf("%s\n", enter[idx_ei++]);
    }
  }

  while (idx_ei < idx_e)
  {
    printf("%s\n", enter[idx_ei++]);
  }
}