import sys

N,M=map(int,input().split())

ls,lk=[],[]
for i in range(0,N):
    ls.append(sys.stdin.readline())
ls.sort()

for i in range(0,M):
    lk.append(sys.stdin.readline())

count=0
for i in lk:
    s=0
    e=N-1
    while s<=e:
        k=(s+e)//2
        if ls[k]==i:
            count+=1
            break
        elif ls[k]<i:
            s=k+1
        elif ls[k]>i:
            e=k-1

print(count)