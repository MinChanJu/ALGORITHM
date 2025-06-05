from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
graph = {i:[] for i in range(1,n+1)}
for _ in range(m):
    a,b,w = map(int,input().split())
    graph[a].append((b,w))
A,B = map(int,input().split())
queue = deque()
queue.append((A,0))
visit = [0]*(n+1)
count = [float('inf')]*(n+1)
count[A] = 0
while queue:
    node,cost = queue.popleft()
    if cost > count[node]:
        continue
    for n_node, n_cost in graph[node]:
        next = cost + n_cost
        if next < count[n_node]:
            count[n_node] = next
            visit[n_node] = node
            queue.append((n_node,next))
path = []
i = B
while 1:
    path.append(i)
    i = visit[i]
    if i == A:
        path.append(A)
        break
path.reverse()
print(count[B])
print(len(path))
print(*path)