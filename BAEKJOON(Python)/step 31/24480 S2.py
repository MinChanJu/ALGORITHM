import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, R = map(int, input().split())
visit = [False] * (N+1)
count = 0
graph = [[] for _ in range(N+1)]
result = [0] * (N+1)

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for edge in graph:
    edge.sort(reverse=True)

def dfs(start):
    global count
    count += 1
    visit[start] = True
    result[start] = count
    for x in graph[start]:
        if not visit[x]:
            dfs(x)

dfs(R)
for i in range(1, N+1):
    print(result[i])