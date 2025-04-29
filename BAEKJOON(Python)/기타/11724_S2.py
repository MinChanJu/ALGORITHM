import sys
input = sys.stdin.readline

def dfs(visit, graph, start):
  stack = [start]
  visit[start] = True
  while (stack):
    node = stack.pop()
    for n_node in graph[node]:
      if (not visit[n_node]):
        visit[n_node] = True
        stack.append(n_node)

N, M = map(int, input().split())
graph = {i: [] for i in range(1, N+1)}
for _ in range(M):
  u, v = map(int, input().split())
  graph[u].append(v)
  graph[v].append(u)

visit = [False]*(N+1)

cnt = 0 
for i in range(1, N+1):
  if (not visit[i]):
    dfs(visit, graph, i)
    cnt += 1

print(cnt)