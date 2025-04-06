import heapq
import sys
input = sys.stdin.readline

V, E = map(int,input().split())
road = [[float("inf")]*(V+1) for _ in range(V+1)]
for _ in range(E):
    a,b,c = map(int,input().split())
    road[a][b]=c

for i in range(1,V+1):
    for j in range(1,V+1):
        for k in range(1,V+1):
            road[i][j]=min(road[i][j], road[i][k]+road[k][j])
Min = float("inf")
for i in range(1,V+1):
    Min = min(Min,road[i][i])
if Min == float("inf"):
    print(-1)
else:
    print(Min)