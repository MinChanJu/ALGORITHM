#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int num;
  struct  Node* next;
} Node;


int main()
{
  int N;
  scanf("%d", &N);

  Node* front = (Node*)malloc(sizeof(Node));
  front->num = 1;
  front->next = NULL;
  Node* back = front;
  for (int i = 2; i <= N; i++)
  {
    back->next = (Node*)malloc(sizeof(Node));
    back = back->next;
    back->num = i;
    back->next = NULL;
  }
  
  while (front->num != back->num)
  {
    Node* prev = front;
    front = front->next;
    back->next = front;
    back = back->next;
    front = front->next;
    free(prev);
  }

  printf("%d\n", front->num);
}