import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
route = [[] for _ in range(N + 1)]
for _ in range(N):
    a, b = map(int, input().split())
    route[a].append(b)
    route[b].append(a)

def dfs(s = 1):
    visit = [False] * (N + 1)
    stack = [(s, [])]
    visit[s] = True

    while stack:
        node, path = stack.pop()
        visit[node] = True
        
        for n_node in route[node]:
            if path and n_node == path[-1]: continue
            if visit[n_node]: return path[path.index(n_node):] + [node]
            stack.append((n_node, path + [node]))

    return []

def bfs(start = []):
    distance = [-1] * (N + 1)
    queue = deque(start)
    for s in start:
        distance[s] = 0
    
    while queue:
        node = queue.popleft()
        
        for n_node in route[node]:
            if distance[n_node] != -1: continue
            distance[n_node] = distance[node] + 1
            queue.append(n_node)
    
    return distance

print(*bfs(dfs())[1:])
