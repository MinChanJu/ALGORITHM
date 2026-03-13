import sys
from collections import deque
input = sys.stdin.readline

N, M, T = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

def bfs(board):
    visit = [[[-1, -1] for _ in range(M)] for _ in range(N)]
    visit[0][0][0] = 0
    queue = deque([(0, 0, 0)])

    while queue:
        i, j, gram = queue.popleft()
        cnt = visit[i][j][gram]

        for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = i + di, j + dj
            if (ni < 0 or ni >= N): continue
            if (nj < 0 or nj >= M): continue
            if (not gram and board[ni][nj] == 1): continue

            next_gram = 1 if gram or board[ni][nj] == 2 else 0
            if visit[ni][nj][next_gram] != -1: continue
            visit[ni][nj][next_gram] = cnt + 1
            queue.append((ni, nj, next_gram))

    return visit

visit = bfs(board)
min_times = []
if visit[N-1][M-1][0] != -1: min_times.append(visit[N-1][M-1][0])
if visit[N-1][M-1][1] != -1: min_times.append(visit[N-1][M-1][1])

if not min_times or min(min_times) > T: print("Fail")
else: print(min(min_times))