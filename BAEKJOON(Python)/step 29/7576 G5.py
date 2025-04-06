from collections import deque
import sys
input = sys.stdin.readline

M, N = map(int,input().split())
tomato = []
for _ in range(N):
    tomato.append(list(map(int,input().split())))
queue = deque()
for i in range(N):
    for j in range(M):
        if tomato[i][j]==1:
            queue.append((i,j))

while queue:
    node = queue.popleft()
    if  node[0]+1 < N and tomato[node[0]+1][node[1]] == 0:
        tomato[node[0]+1][node[1]] = tomato[node[0]][node[1]]+1
        queue.append((node[0]+1,node[1]))
    if  node[1]+1 < M and tomato[node[0]][node[1]+1] == 0:
        tomato[node[0]][node[1]+1] = tomato[node[0]][node[1]]+1
        queue.append((node[0],node[1]+1))
    if  node[0]-1 >= 0 and tomato[node[0]-1][node[1]] == 0:
        tomato[node[0]-1][node[1]] = tomato[node[0]][node[1]]+1
        queue.append((node[0]-1,node[1]))
    if  node[1]-1 >= 0 and tomato[node[0]][node[1]-1] == 0:
        tomato[node[0]][node[1]-1] = tomato[node[0]][node[1]]+1
        queue.append((node[0],node[1]-1))

k=0
for i in range(N):
    for j in range(M):
        if tomato[i][j]==0:
            k=1
if k==0:
    print(tomato[node[0]][node[1]]-1)
else:
    print(-1)