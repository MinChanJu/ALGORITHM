#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);
  int stair[N];
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &stair[i]);
  }

  int dp[N];
  dp[0] = stair[0];
  dp[1] = stair[0] + stair[1];
  dp[2] = (stair[0] > stair[1] ? stair[0] : stair[1]) + stair[2];
  for (int i = 3; i < N; i++)
  {
    dp[i] = (dp[i - 2] > dp[i - 3] + stair[i - 1] ? dp[i - 2] : dp[i - 3] + stair[i - 1]) + stair[i];
  }

  printf("%d\n", dp[N-1]);
}