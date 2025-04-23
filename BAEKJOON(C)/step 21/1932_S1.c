#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);

  int dp[N][N];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      scanf("%d", &dp[i][j]);
    }
  }

  for (int i = 1; i < N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0)
        dp[i][j] += dp[i - 1][j];
      else if (j == i)
        dp[i][j] += dp[i - 1][j - 1];
      else
        dp[i][j] += (dp[i - 1][j] > dp[i - 1][j - 1] ? dp[i - 1][j] : dp[i - 1][j - 1]);
    }
  }

  int max = dp[N-1][0];
  for (int i = 1; i < N; i++)
  {
    if (max < dp[N-1][i]) max = dp[N-1][i];
  }
  
  printf("%d\n", max);
}