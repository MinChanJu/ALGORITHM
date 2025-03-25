import sys
input = sys.stdin.readline

p = 10007
n = int(input())

dp = [0]*(n+2)
dp[1] = 1
dp[2] = 3
for i in range(3, n+1):
  dp[i] = (dp[i-1]+((dp[i-2]*2)%p))%p

print(dp[n])