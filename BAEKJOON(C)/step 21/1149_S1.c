#include <stdio.h>

int main()
{
  int N, r, g, b;
  scanf("%d", &N);

  int home[N][3];
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d %d", &r, &g, &b);
    home[i][0] = r, home[i][1] = g, home[i][2] = b;
  }

  int dp[N][3];
  dp[0][0] = home[0][0], dp[0][1] = home[0][1], dp[0][2] = home[0][2];
  for (int i = 1; i < N; i++)
  {
    dp[i][0] = home[i][0] + (dp[i-1][1] < dp[i-1][2] ? dp[i-1][1] : dp[i-1][2]);
    dp[i][1] = home[i][1] + (dp[i-1][0] < dp[i-1][2] ? dp[i-1][0] : dp[i-1][2]);
    dp[i][2] = home[i][2] + (dp[i-1][0] < dp[i-1][1] ? dp[i-1][0] : dp[i-1][1]);
  }
  
  int min = (dp[N-1][0] < dp[N-1][1] ? dp[N-1][0] : dp[N-1][1]);
  min = (dp[N-1][2] < min ? dp[N-1][2] : min);
  printf("%d\n", min);
}