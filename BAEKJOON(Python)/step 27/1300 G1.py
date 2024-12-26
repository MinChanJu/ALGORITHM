import sys
input=sys.stdin.readline
N=int(input())
K=int(input())
s=1
e=K
while s<=e:
    sum=0
    mid=(s+e)//2
    for i in range(1,N+1):
        if mid//i>N:
            sum+=N
        else:
            sum+=mid//i
    if sum<K:
        s=mid+1
    else:
        e=mid-1
print(s)