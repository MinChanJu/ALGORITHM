import sys
input = sys.stdin.readline

N = int(input())
K = int(input())
MOD = 1000000003

dp = [[0 for j in range(K+1)] for i in range(N+1)]
for i in range(1,N+1):
    dp[i][1] = i

for j in range(2,K+1):
    for i in range(4,N+1):
        if j*2 == i: dp[i][j] = 2
        else: dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % MOD 

print(dp[N][K])