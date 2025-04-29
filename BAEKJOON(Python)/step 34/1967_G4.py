from collections import deque
import sys
input = sys.stdin.readline

V = int(input())
graph = {i:[] for i in range(1,V+1)}
for _ in range(V-1):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
vertex = 1
for _ in range(2):
    count = [float('inf')]*(V+1)
    count[vertex] = 0
    queue = deque()
    queue.append((vertex,0))
    while queue:
        node, cost = queue.popleft()
        if cost > count[node]:
            continue
        for n_node, n_cost in graph[node]:
            next = cost + n_cost
            if next < count[n_node]:
                count[n_node] = next
                queue.append((n_node,next))
    M,j = 0,0
    for d in range(1,V+1):
        if count[d] == float('inf'): continue
        if count[d] > M:
            M = count[d]
            vertex = d
print(M)