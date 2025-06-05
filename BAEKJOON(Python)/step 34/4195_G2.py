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
        rank[x_root] += rank[y_root]
        rank[y_root] = rank[x_root]

T = int(input())
for _ in range(T):
    F = int(input())
    parent = list(range(2*F))
    rank = [1]*(2*F)
    dic = {}
    k = 0
    for i in range(F):
        a, b = map(str,input().split())
        if dic.get(a) == None:
            dic[a] = k
            k += 1
        if dic.get(b) == None:
            dic[b] = k
            k += 1
        union(dic[a],dic[b])
        print(rank[find(dic[a])])