import sys
input = sys.stdin.readline

def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x,y):
    x_root = find(x)
    y_root = find(y)
    if x_root != y_root:
        if rank[x_root] < rank[y_root]:
            parent[x_root] = y_root
        elif rank[x_root] > rank[y_root]:
            parent[y_root] = x_root
        else:
            parent[y_root] = x_root
            rank[x_root] += 1

n,m = map(int,input().split())
parent = list(range(n+1))
rank = [0]*(n+1)
for _ in range(m):
    t,a,b = map(int,input().split())
    if t == 0:
        union(a,b)
    else:
        if find(a) == find(b): print("YES")
        else: print("NO")