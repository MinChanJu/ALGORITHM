from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
graph = {i:[] for i in range(1,n+1)}
for _ in range(m):
    a,b,w = map(int,input().split())
    graph[a].append((b,w))
visit = [[0 for _ in range(n+1)] for _ in range(n+1)]
count = [[float('inf') for _ in range(n+1)] for _ in range(n+1)]
for city in range(1,n+1):
    count[city][city] = 0
    queue = deque()
    queue.append((city,0))
    while queue:
        node, cost = queue.popleft()
        if cost > count[city][node]:
            continue
        for n_node, n_cost in graph[node]:
            next = cost + n_cost
            if next < count[city][n_node]:
                count[city][n_node] = next
                visit[city][n_node] = node
                queue.append((n_node,next))
    for i in range(1,n+1):
        if count[city][i] == float('inf'):
            print(0,end=' ')
        else:
            print(count[city][i],end=' ')
    print('')
for A in range(1,n+1):
    for B in range(1,n+1):
        path = []
        i = B
        k = 0
        while 1:
            path.append(i)
            i = visit[A][i]
            if i == A:
                path.append(A)
                path.reverse()
                break
            if i == 0:
                k = 1
                break
        if k == 1:
            print(0)
        else:
            print(len(path),*path)
            