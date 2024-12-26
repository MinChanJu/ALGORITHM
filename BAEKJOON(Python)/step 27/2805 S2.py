import sys
input=sys.stdin.readline

N,M=map(int,input().split())
ls=list(map(int,input().split()))

s=0
e=max(ls)
while s<=e:
    mid=(s+e)//2
    SUM=0
    for i in ls:
        if i-mid>0:
            SUM+=i-mid
    if SUM>=M:
        s=mid+1
    else:
        e=mid-1
print(e)