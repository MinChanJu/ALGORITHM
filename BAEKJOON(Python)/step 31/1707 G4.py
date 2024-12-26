from collections import deque
import sys
input = sys.stdin.readline

k = int(input())

def bfs(start):
    queue = deque()
    queue.append(start)
    if visit[start]==0:
        visit[start] = 1
    while queue:
        node = queue.popleft()
        if visit[node] == 1:
            s = 2
        elif visit[node] == 2:
            s = 1
        for n_node in graph[node]:
            if visit[n_node] == visit[node]:
                return False
            elif visit[n_node]==0:
                visit[n_node] = s
                queue.append(n_node)
    return True

for _ in range(k):
    V, E = map(int,input().split())
    graph = {i:[] for i in range(V+1)}
    ls = []
    for _ in range(E):
        u, v = map(int,input().split())
        graph[u].append(v)
        graph[v].append(u)
    visit = [0 for _ in range(V+1)]
    k=0
    for i in range(1,V+1):
        if not bfs(i):
            print("NO")
            k=1
            break
    if k==0:
        print("YES")