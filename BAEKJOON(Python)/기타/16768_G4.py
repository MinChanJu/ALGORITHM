import sys
input = sys.stdin.readline

N, K = map(int, input().split())
board = [list(map(int, list(input().strip()))) for _ in range(N)]

def find_delete(board):
    visit = [[False] * 10 for _ in range(N)]
    
    def check(i, j):
        visit[i][j] = True
        stack = [(i, j)]
        total = []
        
        while stack:
            i, j = stack.pop()
            total.append((i, j))
            
            for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= N: continue
                if nj < 0 or nj >= 10: continue
                
                if board[i][j] != board[ni][nj]: continue
                if visit[ni][nj]: continue

                visit[ni][nj] = True
                stack.append((ni, nj))
        
        return total
    
    remove_points = []
    for i in range(N):
        for j in range(10):
            if not visit[i][j] and board[i][j] != 0:
                total = check(i, j)
                if len(total) >= K:
                    remove_points.extend(total)
    
    return remove_points

def fall_hay(board):
    for j in range(10):
        cols = []
        for i in range(N):
            if board[i][j] == 0: continue
            cols.append(board[i][j])
        for i in range(N - len(cols)):
            board[i][j] = 0
        for i in range(N - len(cols), N):
            board[i][j] = cols[i - N + len(cols)]

while True:
    remove_points = find_delete(board)
    if len(remove_points) == 0: break
    
    for i, j in remove_points:
        board[i][j] = 0
    
    fall_hay(board)

for row in board:
    print(*row, sep="")