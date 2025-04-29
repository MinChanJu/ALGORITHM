import sys
input = sys.stdin.readline

INF = 1e9
N = int(input())
W = [list(map(int, input().split())) for _ in range(N)]
dp = [[-1 for _ in range(1 << N)] for _ in range(N)]

def dfs(city, visit):
    if visit == (1 << N) - 1:
        if not W[city][0]:
            return INF
        else:
            return W[city][0]
    if dp[city][visit] != -1:
        return dp[city][visit]
    for i in range(1, N):
        if not visit & (1 << i) and W[city][i]:
            if dp[city][visit] == -1:
                dp[city][visit] = dfs(i, visit | (1 << i)) + W[city][i]
            else:
                dp[city][visit] = min(dp[city][visit], dfs(i, visit | (1 << i)) + W[city][i])
    
    if dp[city][visit] == -1:
        return INF
    
    return dp[city][visit]

print(dfs(0, 1))