from itertools import combinations
N,M=map(int,input().split())
ls=list(map(int,input().split()))
m=0
for i in combinations(ls,3):
    k=i[0]+i[1]+i[2]
    if k<=M:
        m=max(m,k)
print(m)