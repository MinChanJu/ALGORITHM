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
            parent[x_root] = y_root
            rank[y_root] += 1
        return 0
    return 1

n,m = map(int,input().split())
parent = list(range(n))
rank = [1]*(n)
line = []
k = 0
for _ in range(m):
    a,b = map(int,input().split())
    line.append((a,b))
for i in range(m):
    if union(line[i][0],line[i][1]) == 1:
        print(i+1)
        k = 1
        break
if k == 0:
    print(0)
