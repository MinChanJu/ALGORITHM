import sys
n=int(input())
ls=list(map(int,sys.stdin.readline().split()))
ls.sort()
m=int(input())
lk=list(map(int,sys.stdin.readline().split()))
for i in lk:
    s=0
    e=n-1
    while s<=e:
        k=(s+e)//2
        if ls[k]==i:
            print(1,end=' ')
            break
        elif ls[k]<i:
            s=k+1
        elif ls[k]>i:
            e=k-1
    if s>e:
        print(0,end=' ')