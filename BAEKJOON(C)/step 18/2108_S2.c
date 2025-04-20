#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
void printArray(int num[], int size);
int mean(int num[], int size);
int median(int num[], int size);
int mode(int num[], int size);
int range(int num[], int size);

int main()
{
  int N;
  scanf("%d", &N);

  int num[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &num[i]);
  }

  qsort(num, N, sizeof(int), compare);

  printf("%d\n", mean(num, N));
  printf("%d\n", median(num, N));
  printf("%d\n", mode(num, N));
  printf("%d\n", range(num, N));
}

int compare(const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

void printArray(int num[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", num[i]);
  }
  printf("\n");
}

int mean(int num[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += num[i];
  }
  if (sum > 0)
    return (sum + (size / 2)) / size;
  else
    return (sum - (size / 2)) / size;
}

int median(int num[], int size)
{
  return num[size / 2];
}

int mode(int num[], int size)
{
  int check[8001];
  for (int i = 0; i < 8001; i++)
  {
    check[i] = 0;
  }

  for (int i = 0; i < size; i++)
  {
    check[num[i] + 4000]++;
  }

  int max = 0;
  int flag = 0;
  for (int i = 1; i < 8001; i++)
  {
    if (check[max] < check[i])
    {
      flag = 0;
      max = i;
    }
    else if (check[max] == check[i] && flag == 0)
    {
      max = i;
      flag = 1;
    }
  }

  return max - 4000;
}

int range(int num[], int size)
{
  return num[size - 1] - num[0];
}