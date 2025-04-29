import sys
input=sys.stdin.readline
N, K=map(int,input().split())
ls,dp=[],[0 for _ in range(K+1)]
for i in range(N):
    ls.append(list(map(int,input().split())))
for i in ls:
    for j in range(K,i[0]-1,-1):
        dp[j]=max(dp[j],dp[j-i[0]]+i[1])
print(dp[K])