from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int,input().split())
ls = []
for _ in range(N):
    ls.append(list(map(int,list(input().rstrip()))))
visit = [[[0]*2 for _ in range(M)] for _ in range(N)]
queue = deque()
queue.append((1,0,0,0))
s=0
while queue:
    count, wall, y, x = queue.popleft()
    if y == N-1 and x == M-1:
        s=1
        print(count)
        break
    if y+1 < N and visit[y+1][x][wall] == 0:
        if ls[y+1][x] == 1 and wall == 0:
            visit[y+1][x][wall] = 1
            queue.append((count+1,wall+1,y+1,x))
        elif ls[y+1][x] == 0:
            visit[y+1][x][wall] = 1
            queue.append((count+1,wall,y+1,x))
    if x+1 < M and visit[y][x+1][wall] == 0:
        if ls[y][x+1] == 1 and wall == 0:
            visit[y][x+1][wall] = 1
            queue.append((count+1,wall+1,y,x+1))
        elif ls[y][x+1] == 0:
            visit[y][x+1][wall] = 1
            queue.append((count+1,wall,y,x+1))
    if y-1 >= 0 and visit[y-1][x][wall] == 0:
        if ls[y-1][x] == 1 and wall == 0:
            visit[y-1][x][wall] = 1
            queue.append((count+1,wall+1,y-1,x))
        elif ls[y-1][x] == 0:
            visit[y-1][x][wall] = 1
            queue.append((count+1,wall,y-1,x))
    if x-1 >= 0 and visit[y][x-1][wall] == 0:
        if ls[y][x-1] == 1 and wall == 0:
            visit[y][x-1][wall] = 1
            queue.append((count+1,wall+1,y,x-1))
        elif ls[y][x-1] == 0:
            visit[y][x-1][wall] = 1
            queue.append((count+1,wall,y,x-1))
if s==0:
    print(-1)