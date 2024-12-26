from collections import deque
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, R = map(int, input().split())
visit = [False] * (N+1)
graph = [[] for _ in range(N+1)]
result = []
queue=deque()

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for edge in graph:
    edge.sort()

def dfs(R):
    visit[R] = True
    result.append(R)
    for x in graph[R]:
        if not visit[x]:
            dfs(x)

dfs(R)
print(*result)

visit = [False] * (N+1)
result = []

def bfs(R):
    global count
    visit[R] = True
    queue.append(R)
    while queue:
        node =queue.popleft()
        result.append(node)
        for x in graph[node]:
            if visit[x] == False:
                visit[x] = True
                queue.append(x)

bfs(R)
print(*result)