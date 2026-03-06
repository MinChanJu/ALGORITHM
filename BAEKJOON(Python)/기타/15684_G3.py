import sys
input = sys.stdin.readline

N, M, H = map(int, input().split())

ladder_board = [[0] * N for _ in range(H)]
for _ in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    ladder_board[a][b] = 1
    ladder_board[a][b + 1] = -1

def check():
    global ladder_board

    for c in range(N):
        sr, sc = 0, c
        while sr < H:
            sc += ladder_board[sr][sc]
            sr += 1
        if sc != c: return False
    return True

min_cnt = 4
def back(add_cnt = 0, idx = 0):
    global ladder_board, min_cnt
    
    if add_cnt >= min_cnt or check():
        min_cnt = min(min_cnt, add_cnt)
        return

    for id in range(idx, H * (N - 1)):
        r = id // (N - 1)
        c = id % (N - 1)

        if ladder_board[r][c] != 0: continue
        if ladder_board[r][c + 1] != 0: continue
        
        ladder_board[r][c], ladder_board[r][c + 1] = 1, -1
        back(add_cnt + 1, id + 1)
        ladder_board[r][c], ladder_board[r][c + 1] = 0, 0

back()
if min_cnt > 3: print(-1)
else: print(min_cnt)
