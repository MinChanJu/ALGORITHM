import sys
input=sys.stdin.readline
n=int(input())
ls=list(map(int,input().split()))
lp=[1]*n
for i in range(n):
    for j in range(i):
        if ls[i]>ls[j]:
            lp[i]=max(lp[i],lp[j]+1)
print(max(lp))