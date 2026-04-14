import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

max_score = 0
max_point = max(map(max, board))
visit = [[False] * M for _ in range(N)]
def dfs(tetromino, depth, score):
    global max_score
    if depth == 4:
        max_score = max(max_score, score)
        return

    if score + max_point * (4 - depth) <= max_score: return

    for i, j in tetromino:
        for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= N: continue
            if nj < 0 or nj >= M: continue
            
            if visit[ni][nj]: continue
            visit[ni][nj] = True
            dfs(tetromino + [(ni, nj)], depth + 1, score + board[ni][nj])
            visit[ni][nj] = False

for i in range(N):
    for j in range(M):
        visit[i][j] = True
        dfs([(i, j)], 1, board[i][j])
        visit[i][j] = False

print(max_score)
