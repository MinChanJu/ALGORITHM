import sys
n,m=map(int,sys.stdin.readline().split())
ls={}
for i in range(n):
    a=(sys.stdin.readline().strip())
    ls[a]=i+1
    ls[i+1]=a
for _ in range(m):
    a=sys.stdin.readline().strip()
    if a.isdigit()==True:
        a=int(a)
        print(ls[a])
    elif a.isdigit()==False:
        print(ls[a])