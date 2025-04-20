#include <stdio.h>
#include <stdlib.h>

int **createStar(int N);
void starRecursion(int **star, int a1, int b1, int a2, int b2);
void printStar(int **star, int N);

int main()
{
  int N;
  scanf("%d", &N);

  int **star = createStar(N);
  starRecursion(star, 0, 0, N-1, N-1);
  printStar(star, N);
}

int **createStar(int N)
{
  int **star = (int **)malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++)
  {
    star[i] = (int *)malloc(sizeof(int) * N);
    for (int j = 0; j < N; j++)
    {
      star[i][j] = '*';
    }
  }
  return star;
}

void starRecursion(int **star, int a1, int b1, int a2, int b2)
{
  if (a1 == a2 && b1 == b2)
    return;
  int m = (a2 - a1 + 1) / 3;

  starRecursion(star, a1, b1, a1 + m - 1, b1 + m - 1);
  starRecursion(star, a1 + m, b1, a1 + m + m - 1, b1 + m - 1);
  starRecursion(star, a1 + m + m, b1, a1 + m + m + m - 1, b1 + m - 1);

  starRecursion(star, a1, b1 + m, a1 + m - 1, b1 + m + m - 1);
  for (int i = a1 + m; i < a1 + m + m; i++)
  {
    for (int j = b1 + m; j < b1 + m + m; j++)
    {
      star[i][j] = ' ';
    }
  }
  starRecursion(star, a1 + m + m, b1 + m, a1 + m + m + m - 1, b1 + m + m - 1);

  starRecursion(star, a1, b1 + m + m, a1 + m - 1, b1 + m + m + m - 1);
  starRecursion(star, a1 + m, b1 + m + m, a1 + m + m - 1, b1 + m + m + m - 1);
  starRecursion(star, a1 + m + m, b1 + m + m, a1 + m + m + m - 1, b1 + m + m + m - 1);
}

void printStar(int **star, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%c", star[i][j]);
    }
    printf("\n");
  }
}