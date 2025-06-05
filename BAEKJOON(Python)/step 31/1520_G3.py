import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

M, N = map(int, input().split())
board = []
for _ in range(M):
    board.append(list(map(int, input().split())))
dp = [[-1] * N for _ in range(M)]

dx, dy = [1, 0, 0, -1], [0, 1, -1, 0]

def DFS(x, y):
    if x == M-1 and y == N-1: return 1
    if dp[x][y] != -1: return dp[x][y]
    dp[x][y] = 0
    for i in range(4):
        nx, ny = dx[i] + x, dy[i] + y
        if 0 <= nx < M and 0 <= ny < N:
            if board[nx][ny] < board[x][y]:
                dp[x][y] += DFS(nx, ny)
    return dp[x][y]

print(DFS(0, 0))