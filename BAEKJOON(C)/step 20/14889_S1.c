#include <stdio.h>
#include <stdlib.h>

void dfs(int start_idx, int link_idx, int s);

int N, **S, *start, *link;
int min = 40000;

int main()
{
  scanf("%d", &N);

  S = (int **)malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++)
  {
    S[i] = (int *)malloc(sizeof(int) * N);
    for (int j = 0; j < N; j++)
      scanf("%d", &S[i][j]);
  }

  start = (int *)malloc(sizeof(int) * (N / 2));
  link = (int *)malloc(sizeof(int) * (N / 2));

  dfs(0, 0, 0);
  printf("%d\n", min);
}

void dfs(int start_idx, int link_idx, int s)
{
  if (start_idx == N / 2 && link_idx == N / 2)
  {
    int sum_start = 0, sum_link = 0;
    for (int i = 0; i < N / 2; i++)
    {
      for (int j = i + 1; j < N / 2; j++)
      {
        sum_start += S[start[i]][start[j]] + S[start[j]][start[i]];
        sum_link += S[link[i]][link[j]] + S[link[j]][link[i]];
      }
    }

    int abs = sum_start > sum_link ? sum_start - sum_link : sum_link - sum_start;
    if (min > abs)
      min = abs;
    return;
  }
  if (start_idx == N / 2)
  {
    for (int i = s; i < N; i++)
    {
      link[link_idx++] = i;
    }

    int sum_start = 0, sum_link = 0;
    for (int i = 0; i < N / 2; i++)
    {
      for (int j = i + 1; j < N / 2; j++)
      {
        sum_start += S[start[i]][start[j]] + S[start[j]][start[i]];
        sum_link += S[link[i]][link[j]] + S[link[j]][link[i]];
      }
    }

    int abs = sum_start > sum_link ? sum_start - sum_link : sum_link - sum_start;
    if (min > abs)
      min = abs;
    return;
  }
  if (link_idx == N / 2)
  {
    for (int i = s; i < N; i++)
    {
      start[start_idx++] = i;
    }

    int sum_start = 0, sum_link = 0;
    for (int i = 0; i < N / 2; i++)
    {
      for (int j = i + 1; j < N / 2; j++)
      {
        sum_start += S[start[i]][start[j]] + S[start[j]][start[i]];
        sum_link += S[link[i]][link[j]] + S[link[j]][link[i]];
      }
    }

    int abs = sum_start > sum_link ? sum_start - sum_link : sum_link - sum_start;
    if (min > abs)
      min = abs;
    return;
  }

  start[start_idx] = s;
  dfs(start_idx + 1, link_idx, s + 1);

  link[link_idx] = s;
  dfs(start_idx, link_idx + 1, s + 1);
}