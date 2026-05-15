import sys
input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(map(int, input().rstrip())) for _ in range(N)]

count_map = [0, 0]

def dfs(i, j, m):
    stack = [(i, j)]
    board[i][j] = m
    cnt = 1
    
    while stack:
        i, j = stack.pop()
        
        for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= N: continue
            if nj < 0 or nj >= M: continue
            
            if board[ni][nj] != 0: continue
            board[ni][nj] = m
            cnt += 1
            cnt %= 10
            stack.append((ni, nj))
    
    return cnt

mark = 2
for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            cnt = dfs(i, j, mark)
            count_map.append(cnt)
            mark += 1

for i in range(N):
    for j in range(M):
        if board[i][j] != 1: print(0, end="")
        else:
            marks = set()
            for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= N: continue
                if nj < 0 or nj >= M: continue
                
                if board[ni][nj] == 1: continue
                marks.add(board[ni][nj])
            
            cnt = 1
            for mark in marks:
                cnt += count_map[mark]
                cnt %= 10
            
            print(cnt, end="")
    print()
