import sys
input=sys.stdin.readline

n,k=map(int,input().split())
ls=[]
dp=[0 for _ in range(k+1)]
for i in range(n):
    a=int(input())
    if a<=k:
        ls.append(a)

dp[0]=1
for i in ls:
    for j in range(i,k+1):
        dp[j]+=dp[j-i]

print(dp[k])