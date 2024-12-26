import heapq
import sys
input = sys.stdin.readline

N, M = map(int,input().split())
edge_list = []
for _ in range(M):
    A, B, C = map(int,input().split())
    edge_list.append((A,B,C))
visit = [float("inf") for _ in range(N+2)]
visit[1]=0
for node in range(N-1):
    for u,v,w in edge_list:
        if visit[u] != float("inf") and visit[u]+w < visit[v]:
            visit[v] = visit[u]+w
cycle=0
for u,v,w in edge_list:
    if visit[u] != float("inf") and visit[u]+w < visit[v]:
        cycle=1
        print(-1)
        break
if cycle == 0:
    for node in range(2,N+1):
        if visit[node] == float("inf"):
            print(-1)
        else:
            print(visit[node])