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

N = int(input())
M = int(input())
parent = list(range(N+1))
rank = [0]*(N+1)
for i in range(1,N+1):
    ls = list(map(int,input().split()))
    for j in range(N):
        if ls[j]: union(i,j+1)
k = 0
plan = list(map(int,input().split()))
for i in range(M-1):
    if find(plan[i]) != find(plan[i+1]): k = 1
if k == 0: print("YES")
else: print("NO")