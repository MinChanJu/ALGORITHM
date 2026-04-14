import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4)

M, N = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(M)]

dp = [[-1] * N for _ in range(M)]
dp[0][0] = 1

def dfs(i, j):
    if dp[i][j] != -1: return dp[i][j]
    dp[i][j] = 0

    if i - 1 >= 0 and board[i-1][j] > board[i][j]:
        dp[i][j] += dfs(i-1,j)
    if i + 1 < M and board[i+1][j] > board[i][j]:
        dp[i][j] += dfs(i+1,j)
    if j - 1 >= 0 and board[i][j-1] > board[i][j]:
        dp[i][j] += dfs(i,j-1)
    if j + 1 < N and board[i][j+1] > board[i][j]:
        dp[i][j] += dfs(i,j+1)
    
    return dp[i][j]

print(dfs(M - 1, N - 1))