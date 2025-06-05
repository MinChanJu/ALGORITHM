from collections import deque
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

N, M, R = map(int, input().split())
visit = [False] * (N+1)
count = 0
graph = [[] for _ in range(N+1)]
result = [0] * (N+1)
queue=deque()

for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for edge in graph:
    edge.sort()

def bfs(R):
    global count
    visit[R] = True
    queue.append(R)
    while queue:
        node =queue.popleft()
        count+=1
        result[node]=count
        for x in graph[node]:
            if visit[x] == False:
                visit[x] = True
                queue.append(x)

bfs(R)
for i in range(1, N+1):
    print(result[i])