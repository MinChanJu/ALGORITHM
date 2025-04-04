#include <stdio.h>

#define MAX 246913

int main()
{
  int prime[MAX];
  for (int i = 0; i < MAX; i++)
  {
    prime[i] = 1;
  }

  prime[0] = prime[1] = 0;

  for (int i = 2; i < MAX; i++)
  {
    if (prime[i])
    {
      for (int j = 2*i; j < MAX; j += i)
      {
        prime[j] = 0;
      }
    }
  }

  while (1)
  {
    int n;
    scanf("%d", &n);
    if (n == 0) break;

    int cnt = 0;
    for (int i = n+1; i <= 2*n; i++)
      cnt += prime[i];
    
    printf("%d\n", cnt);
  }
  
}