import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

for i in range(N):
    for j in range(N):
        if board[i][j] == 9:
            shark_i, shark_j, shark_size = i, j, 2
            board[i][j] = 0
            break

def find_edible_fish(shark_i, shark_j, shark_size):
    visit = [[-1] * N for _ in range(N)]
    visit[shark_i][shark_j] = 0
    queue = deque([(shark_i, shark_j)])
    
    edible_fish = []
    min_dist = float("inf")
    while queue:
        i, j = queue.popleft()
        if visit[i][j] >= min_dist: continue
        
        for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or nj < 0 or ni >= N or nj >= N: continue
            if visit[ni][nj] != -1: continue
            if board[ni][nj] > shark_size: continue
            visit[ni][nj] = visit[i][j] + 1
            if 0 < board[ni][nj] < shark_size:
                edible_fish.append((visit[ni][nj], ni, nj))
                min_dist = visit[ni][nj]
                continue
            queue.append((ni, nj))
    
    edible_fish.sort()
    return edible_fish[0] if edible_fish else None

time, eat_cnt = 0, 0
while True:
    fish = find_edible_fish(shark_i, shark_j, shark_size)
    
    if fish is None: break
    
    fish_dist, fish_i, fish_j = fish
    time += fish_dist
    eat_cnt += 1
    shark_i, shark_j = fish_i, fish_j
    board[shark_i][shark_j] = 0
    
    if eat_cnt == shark_size:
        shark_size += 1
        eat_cnt = 0

print(time)
