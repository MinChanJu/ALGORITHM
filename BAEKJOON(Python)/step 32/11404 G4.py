import heapq
import sys
input = sys.stdin.readline

def dikstra(start,graph,N):
    diatance = [float("inf")]*(N+1)
    diatance[start] = 0
    heap = []
    heapq.heappush(heap,(0,start))
    while heap:
        cost, node = heapq.heappop(heap)
        if diatance[node] < cost:
            continue
        for dis, n_node in graph[node]:
            if dis+cost < diatance[n_node]:
                diatance[n_node]=dis+cost
                heapq.heappush(heap,(dis+cost,n_node))
    return diatance

n = int(input())
m = int(input())
bus = {i:[] for i in range(1,n+1)}
for _ in range(m):
    a,b,c = map(int,input().split())
    bus[a].append((c,b))

for i in range(1,n+1):
    distance = dikstra(i,bus,n)
    for i in range(1,n+1):
        if distance[i] == float("inf"):
            print(0, end=' ')
        else:
            print(distance[i], end=' ')
    print('')