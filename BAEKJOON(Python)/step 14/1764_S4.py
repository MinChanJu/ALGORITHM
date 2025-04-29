import sys
n,m=map(int,sys.stdin.readline().split())
ls,lk={},[]
for i in range(n):
    a=sys.stdin.readline().strip()
    ls[a]=1
for i in range(m):
    a=sys.stdin.readline().strip()
    if ls.get(a)!=None:
        lk.append(a)
print(len(lk))
lk.sort()
for i in lk:
    print(i)