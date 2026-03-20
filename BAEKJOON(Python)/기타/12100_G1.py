import sys
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

def rotate_board(board, cnt):
    for _ in range(cnt):
        board = [[board[N-1-j][i] for j in range(N)] for i in range(N)]
    return board

def move_board(board, dir):
    if dir == "up": cnt = 1
    elif dir == "left": cnt = 2
    elif dir == "down": cnt = 3
    else: cnt = 0
    
    board = rotate_board(board, cnt)
    
    temp_board = []
    for i in range(N):
        sub = [0] * N
        idx = N - 1
        last = None
        for j in range(N-1, -1, -1):
            if board[i][j] == 0: continue
            if board[i][j] == last:
                sub[idx] = 2 * last
                last = None
                idx -= 1
            else:
                if last != None:
                    sub[idx] = last
                    idx -= 1
                last = board[i][j]
        if last != None:
            sub[idx] = last
        temp_board.append(sub)
    
    board = rotate_board(temp_board, 4-cnt)
    
    return board

max_val = 0
def back(dirs = [], board = board):
    global max_val
    if len(dirs) == 5:
        for i in range(N):
            for j in range(N):
                max_val = max(max_val, board[i][j])
        return

    for dir in ["right", "down", "left", "up"]:
        temp_board = [[board[i][j] for j in range(N)] for i in range(N)]
        temp_board = move_board(temp_board, dir)
        back(dirs + [dir], temp_board)

back()
print(max_val)
