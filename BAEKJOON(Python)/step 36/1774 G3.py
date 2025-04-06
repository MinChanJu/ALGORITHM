import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def get_dist(i,j):
    a,b,c,d = space[i][0], space[i][1], space[j][0], space[j][1]
    return ((a - c) ** 2 + (b - d) ** 2) ** 0.5

def find(node):
    if node != parent[node]:
        parent[node] = find(parent[node])
    return parent[node]

def union(a, b):
    a, b = find(a), find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N, M = map(int, input().split())
space = [(0,0)]
for _ in range(N):
    x, y = map(float,input().split())
    space.append((x,y))
cnt = N-1
parent = list(range(N+1))
for _ in range(M):
    x, y = map(int, input().split())
    if find(x) != find(y):
        union(x, y)
        cnt -= 1
graph = []
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if i != j:
            graph.append((i, j, get_dist(i,j)))
graph.sort(key=lambda x: x[2], reverse=True)

val = 0
while cnt:
    a, b, c = graph.pop()
    if find(a) != find(b):
        cnt -= 1
        union(a, b)
        val += c
print("{:.2f}".format(val))