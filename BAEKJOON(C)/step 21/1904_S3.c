#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int dp[N + 1];
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= N; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  }

  printf("%d\n", dp[N]);
}