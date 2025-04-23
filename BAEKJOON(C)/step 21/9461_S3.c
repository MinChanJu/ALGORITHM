#include <stdio.h>

int main()
{
  long dp[101];
  dp[1] = dp[2] = dp[3] = 1;
  dp[4] = dp[5] = 2;
  for (int i = 6; i <= 100; i++)
  {
    dp[i] = dp[i-1] + dp[i-5];
  }

  int T, N;
  scanf("%d", &T);

  while (T--)
  {
    scanf("%d", &N);
    printf("%ld\n", dp[N]);
  }
}