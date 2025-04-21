#include <stdio.h>
#include <stdlib.h>

typedef struct Position
{
  int i, j;
  struct Position *next, *prev;
} Position;

Position *createNode(int i, int j);
void push(int i, int j);
int check_r(int i, int key);
int check_c(int j, int key);
int check_s(int i, int j, int key);
void dfs(Position *cur);

int sudoku[9][9];
Position *front, *back;

int main()
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      scanf("%d", &sudoku[i][j]);
      if (sudoku[i][j] == 0)
        push(i, j);
    }
  }
  dfs(front);
}

Position *createNode(int i, int j)
{
  Position *new = (Position *)malloc(sizeof(Position));
  new->i = i;
  new->j = j;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void push(int i, int j)
{
  Position *new = createNode(i, j);
  if (front == NULL)
  {
    front = back = new;
  }
  else
  {
    back->next = new;
    new->prev = back;
    back = new;
  }
}

int check_r(int i, int key)
{
  for (int j = 0; j < 9; j++)
  {
    if (sudoku[i][j] == key)
      return 0;
  }
  return 1;
}

int check_c(int j, int key)
{
  for (int i = 0; i < 9; i++)
  {
    if (sudoku[i][j] == key)
      return 0;
  }
  return 1;
}

int check_s(int i, int j, int key)
{
  int mi = i / 3 * 3, mj = j / 3 * 3;
  for (int ai = mi; ai < mi + 3; ai++)
  {
    for (int aj = mj; aj < mj + 3; aj++)
    {
      if (sudoku[ai][aj] == key)
        return 0;
    }
  }
  return 1;
}

void dfs(Position *cur)
{
  if (cur == NULL)
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        printf("%d ", sudoku[i][j]);
      }
      printf("\n");
    }
    exit(0);
  }
  for (int key = 1; key <= 9; key++)
  {
    int i = cur->i, j = cur->j;
    if (check_r(i, key) && check_c(j, key) && check_s(i, j, key))
    {
      sudoku[i][j] = key;
      dfs(cur->next);
      sudoku[i][j] = 0;
    }
  }
}