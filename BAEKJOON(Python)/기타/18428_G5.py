import sys
from itertools import combinations
input = sys.stdin.readline

N = int(input())
board = [input().split() for _ in range(N)]

student = [(i, j) for i in range(N) for j in range(N) if board[i][j] == "S"]
empty = [(i, j) for i in range(N) for j in range(N) if board[i][j] == "X"]

avoidable = False

for ls in combinations(empty, 3):
    for i, j in ls:
        board[i][j] = "O"
        
    check = True
    for i, j in student:
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = i + dx, j + dy
            while 0 <= ni < N and 0 <= nj < N and board[ni][nj] != "O":
                if (board[ni][nj] == "T"):
                    check = False
                    break
                ni += dx
                nj += dy
            if not check: break
        if not check: break
    
    if check:
        avoidable = True
        break
    
    for i, j in ls:
        board[i][j] = "X"

if avoidable:
    print("YES")
else:
    print("NO")
