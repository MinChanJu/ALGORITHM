import sys
input=sys.stdin.readline

K,N=map(int,input().split())
ls=[]
for i in range(K):
    ls.append(int(input()))
s=0
e=sum(ls)//N
ls.sort()
while s<=e:
    t=(s+e)//2
    SUM=0
    if t==0:
        break
    for i in ls:
        SUM+=i//t
    if SUM>=N:
        s=t+1
    elif SUM<N:
        e=t-1
print(e)