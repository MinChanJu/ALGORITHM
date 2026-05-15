import sys
input = sys.stdin.readline

N, M = map(int, input().split())
school = [0] + input().split()

edges = [list(map(int, input().split())) for _ in range(M)]
edges.sort(key=lambda x: x[2])
parent = [-1] * (N + 1)

def find(x):
    if parent[x] == -1: return x
    parent[x] = find(parent[x])
    return parent[x]

def union(x, y):
    x_root, y_root = find(x), find(y)
    if x_root == y_root: return False
    
    parent[y_root] = x_root
    return True

total, cnt = 0, 0
for u, v, d in edges:
    if school[u] != school[v] and union(u, v):
        total += d
        cnt += 1
    if cnt == N - 1: break

if cnt == N - 1: print(total)
else: print(-1)



import sys, heapq
input = sys.stdin.readline

N, M = map(int, input().split())
school = [0] + input().split()

graph = [[] for _ in range(N + 1)]
for _ in range(M):
    u, v, d = map(int, input().split())
    graph[u].append((v, d))
    graph[v].append((u, d))

visit = [False] * (N + 1)
visit[1] = True
heap = []

for n_node, distance in graph[1]:
    if school[1] == school[n_node]: continue
    heapq.heappush(heap, (distance, n_node))

total = 0
cnt = 0
while heap and cnt < N - 1:
    distance, node = heapq.heappop(heap)
    
    if visit[node]: continue
    visit[node] = True
    total += distance
    cnt += 1
    
    for n_node, distance in graph[node]:
        if visit[n_node]: continue
        if school[node] == school[n_node]: continue
        heapq.heappush(heap, (distance, n_node))

if cnt == N - 1: print(total)
else: print(-1)
