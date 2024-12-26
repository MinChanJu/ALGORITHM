import sys
input = sys.stdin.readline()

M, N = map(int, input().split())
graph = []
for _ in range(M):
    graph.append(list(map(int, input().split())))
dp = [[-1] * N for _ in range(M)]

xd = [-1, 1, 0, 0]
yd = [0, 0, -1, 1]

def DFS(x, y):
    if x == M-1 and y == N-1:
        return 1
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = 0
    for i in range(4):
        nx, ny = xd[i] + x, yd[i] + y
        if nx >= 0 and nx < M and ny >= 0 and ny < N:
            if graph[nx][ny] < graph[x][y]:
                dp[x][y] += DFS(nx, ny)
    return dp[x][y]

print(DFS(0, 0))