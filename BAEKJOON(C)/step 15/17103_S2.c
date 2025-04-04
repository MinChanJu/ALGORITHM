#include <stdio.h>
#include <math.h>

#define MAX 1000001

int main()
{
  int prime[MAX];
  for (int i = 0; i < MAX; i++) prime[i] = 1;
  prime[0] = prime[1] = 0;

  for (int i = 0; i < MAX; i++)
  {
    if (prime[i])
    {
      for (int j = 2*i; j < MAX; j += i)
      {
        prime[j] = 0;
      }
    }
  }
  
  int T;
  scanf("%d", &T);

  while (T--)
  {
    int N;
    scanf("%d", &N);

    int cnt = 0;
    for (int i = 2; i <= N/2; i++)
    {
      if (prime[i] && prime[N-i]) cnt++;
    }
    
    printf("%d\n", cnt);
  }
  
  return 0;
}