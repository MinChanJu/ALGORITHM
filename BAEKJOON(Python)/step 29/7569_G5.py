from collections import deque
import sys
input = sys.stdin.readline

M, N, H = map(int,input().split())
tomato = [[] for _ in range(H)]
for i in range(H):
    for _ in range(N):
        tomato[i].append(list(map(int,input().split())))
queue = deque()
for i in range(H):
    for j in range(N):
        for k in range(M):
            if tomato[i][j][k]==1:
                queue.append((i,j,k))

while queue:
    node = queue.popleft()
    if  node[0]+1 < H and tomato[node[0]+1][node[1]][node[2]] == 0:
        tomato[node[0]+1][node[1]][node[2]] = tomato[node[0]][node[1]][node[2]]+1
        queue.append((node[0]+1,node[1],node[2]))
    if  node[1]+1 < N and tomato[node[0]][node[1]+1][node[2]] == 0:
        tomato[node[0]][node[1]+1][node[2]] = tomato[node[0]][node[1]][node[2]]+1
        queue.append((node[0],node[1]+1,node[2]))
    if  node[2]+1 < M and tomato[node[0]][node[1]][node[2]+1] == 0:
        tomato[node[0]][node[1]][node[2]+1] = tomato[node[0]][node[1]][node[2]]+1
        queue.append((node[0],node[1],node[2]+1))
    
    if  node[0]-1 >= 0 and tomato[node[0]-1][node[1]][node[2]] == 0:
        tomato[node[0]-1][node[1]][node[2]] = tomato[node[0]][node[1]][node[2]]+1
        queue.append((node[0]-1,node[1],node[2]))
    if  node[1]-1 >= 0 and tomato[node[0]][node[1]-1][node[2]] == 0:
        tomato[node[0]][node[1]-1][node[2]] = tomato[node[0]][node[1]][node[2]]+1
        queue.append((node[0],node[1]-1,node[2]))
    if  node[2]-1 >= 0 and tomato[node[0]][node[1]][node[2]-1] == 0:
        tomato[node[0]][node[1]][node[2]-1] = tomato[node[0]][node[1]][node[2]]+1
        queue.append((node[0],node[1],node[2]-1))

s=0
for i in range(H):
    for j in range(N):
        for k in range(M):
            if tomato[i][j][k]==0:
                s=1
if s==0:
    print(tomato[node[0]][node[1]][node[2]]-1)
else:
    print(-1)