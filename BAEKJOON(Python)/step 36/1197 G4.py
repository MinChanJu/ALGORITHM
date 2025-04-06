import heapq
import sys
input = sys.stdin.readline

def prim(graph, start):
    mst = []
    visited = set([start])
    edges = [(weight, start, v) for v, weight in graph[start]]
    heapq.heapify(edges)
    while edges:
        weight, u, v = heapq.heappop(edges)
        if v not in visited:
            visited.add(v)
            mst.append((u, v, weight))
            for next_vertex, weight in graph[v]:
                if next_vertex not in visited:
                    heapq.heappush(edges, (weight, v, next_vertex))
    return mst

V, E = map(int,input().split())
graph = {i:[] for i in range(1,V+1)}
for _ in range(E):
    a, b, c = map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
mst = prim(graph,1)
val = 0
for edge in mst:
    val += edge[2]
print(val)