import sys
input=sys.stdin.readline
N=int(input())
ls=list(map(int,input().split()))
ls.sort()
dp=[0]*N
dp[0]=ls[0]
for i in range(1,N):
    dp[i]=dp[i-1]+ls[i]
print(sum(dp))