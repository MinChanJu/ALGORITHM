import sys
input=sys.stdin.readline
N,M=map(int,input().split())
ls,d=[],{}
for _ in range(N):
    a=input().strip()
    if len(a)>=M:
        if d.get(a)==None:
            d[a]=1
        else:
            d[a]+=1
for i in d:
    ls.append([i,d[i]])
ls.sort(key=lambda x : (-x[1],-len(x[0]),x[0]))
for i in ls:
    print(i[0])