from collections import deque
import sys
input = sys.stdin.readline

def BFS(graph, start, N):
    visit = [0 for _ in range(N+1)]
    queue = deque()
    queue.append(start)

    while queue:
        node = queue.popleft()
        if visit[node]==0:
            visit[node]=1
            for n_node in graph[node].keys():
                queue.append(n_node)
    return visit.count(1)-1

N = int(input())
S = int(input())

com = {i:{} for i in range(1,N+1)}

for _ in range(S):
    a, b = map(int,input().split())
    com[a][b]=True
    com[b][a]=True

print(BFS(com,1,N))