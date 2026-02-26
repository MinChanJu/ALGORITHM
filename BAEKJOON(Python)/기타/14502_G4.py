import sys
from itertools import combinations
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

def dfs(board, i, j):
    stack = [(i, j)]
    
    while stack:
        si, sj = stack.pop()
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = si + dx, sj + dy
            if ni < 0 or ni >= N or nj < 0 or nj >= M: continue
            if board[ni][nj] != 0: continue
            board[ni][nj] = 2
            stack.append((ni, nj))

def countSaveArea(board):
    for i in range(N):
        for j in range(M):
            if board[i][j] == 2:
                dfs(board, i, j)
    
    cnt = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 0:
                cnt += 1
                
    return cnt

max_cnt = 0
empty = [(i, j) for i in range(N) for j in range(M) if board[i][j] == 0]
for ls in combinations(empty, 3):
    copy_board = [[board[i][j] for j in range(M)] for i in range(N)]
    for i, j in ls:
        copy_board[i][j] = 1
    
    max_cnt = max(max_cnt, countSaveArea(copy_board))

print(max_cnt)
