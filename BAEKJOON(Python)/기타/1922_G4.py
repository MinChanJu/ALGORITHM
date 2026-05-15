import sys, heapq
input = sys.stdin.readline

N = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b, c = map(int, input().split())
    if a == b: continue
    graph[a].append((b, c))
    graph[b].append((a, c))

visited = [False] * (N + 1)
visited[1] = True
heap = []

for next_vertex, weight in graph[1]:
    heapq.heappush(heap, (weight, 1, next_vertex))

total_cost = 0
cnt = 0
while heap and cnt < N - 1:
    weight, from_vertex, to_vertex = heapq.heappop(heap)

    if visited[to_vertex]:
        continue

    visited[to_vertex] = True
    total_cost += weight
    cnt += 1

    for next_vertex, next_weight in graph[to_vertex]:
        if not visited[next_vertex]:
            heapq.heappush(heap, (next_weight, to_vertex, next_vertex))

print(total_cost)
