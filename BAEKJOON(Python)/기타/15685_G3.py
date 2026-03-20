import sys
input = sys.stdin.readline

dirs = [(1, 0), (0, -1), (-1, 0), (0, 1)]
board = [[0] * 101 for _ in range(101)]
curves = [0] * (2 ** 10)
for g in range(1, 11):
    prev_g = 2 ** (g - 1)
    cur_g = 2 * prev_g
    for i in range(prev_g, cur_g):
        curves[i] = (curves[cur_g - i - 1] + 1) % 4

N = int(input())
for _ in range(N):
    x, y, d, g = map(int, input().split())
    cur_g = 2 ** g
    board[x][y] = 1
    for i in range(cur_g):
        dx, dy = dirs[(curves[i] + d) % 4]
        x, y = x + dx, y + dy
        board[x][y] = 1

cnt = 0
for i in range(100):
    for j in range(100):
        if board[i][j] != 0 and board[i+1][j] != 0 and board[i][j+1] != 0 and board[i+1][j+1] != 0: cnt += 1

print(cnt)
