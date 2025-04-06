import sys
import heapq

V, E = map(int, input().split())
K = int(input())
graph = {i:[] for i in range(1,V+1)}
for _ in range(E):
    u, v, w = map(int,input().split())
    graph[u].append((w,v))
visit = [30000000 for _ in range(V+1)]
visit[K]=0
queue = []
heapq.heappush(queue, (0, K))
while queue:
    cost, node = heapq.heappop(queue)
    if visit[node] < cost:
        continue
    for c, n_node in graph[node]:
        if cost + c < visit[n_node]:
            visit[n_node] = cost + c
            heapq.heappush(queue, (cost + c, n_node))
for i in range(1,V+1):
    if visit[i] == 30000000:
        print("INF")
    else:
        print(visit[i])