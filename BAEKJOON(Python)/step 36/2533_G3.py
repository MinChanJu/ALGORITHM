from collections import deque
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def DFS(graph, nodeIdx, parentIdx):
    visit[nodeIdx] = 1
    for node in graph[nodeIdx]:
        if visit[node] == 0:
            DFS(graph, node, nodeIdx)
    if parentIdx:
        if not EA[nodeIdx]:
            EA[parentIdx] = True

N = int(input())
graph = {i:[] for i in range(1,N+1)}
EA = [False] * (N+1)  # Early Adapter
visit = [0] * (N+1)

for i in range(N-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

DFS(graph, 1, 0)
cnt = 0
for node in EA:
    if node: cnt += 1
print(cnt)