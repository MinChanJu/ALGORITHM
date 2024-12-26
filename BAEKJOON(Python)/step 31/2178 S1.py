from collections import deque
import sys
input=sys.stdin.readline

N,M=map(int,input().split())

A=[[0 for i in range(M+2)]]
for _ in range(N):
    A.append([0]+list(map(int,list(input().strip())))+[0])
A.append([0 for i in range(M+2)])

graph={(i,j):{} for i in range(N) for j in range(M)}

for i in range(N):
    for j in range(M):
        if A[i+1][j+1]==0:
            continue
        if A[i][j+1]:
            graph[(i,j)][(i-1,j)]=True
        if A[i+1][j]:
            graph[(i,j)][(i,j-1)]=True
        if A[i+2][j+1]:
            graph[(i,j)][(i+1,j)]=True
        if A[i+1][j+2]:
            graph[(i,j)][(i,j+1)]=True

def BFS(graph,start,k):
    visit=[[False for i in range(k[1])] for j in range(k[0])]
    queue=deque()
    queue.append(start)
    while queue:
        node=queue.popleft()
        if not visit[node[0]][node[1]]:
            visit[node[0]][node[1]]=True
            for i in graph[node].keys():
                if not visit[i[0]][i[1]]:
                    queue.append(i)
                    A[i[0]+1][i[1]+1]=A[node[0]+1][node[1]+1]+1
    return A[N][M]

print(BFS(graph,(0,0),(N,M)))