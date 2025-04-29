import sys
input=sys.stdin.readline
N,M=map(int,input().split())
ls=[]
for _ in range(N):
    ls.append(list(map(int,input().split())))
dp=[[0 for _ in range(N+1)] for _ in range(N+1)]
for i in range(1,N+1):
    dp[i][1]=dp[i-1][1]+ls[i-1][0]
for i in range(1,N+1):
    dp[1][i]=dp[1][i-1]+ls[0][i-1]
for i in range(2,N+1):
    for j in range(2,N+1):
        dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+ls[i-1][j-1]
for _ in range(M):
    y1,x1,y2,x2=map(int,input().split())
    print(dp[y2][x2]-dp[y2][x1-1]-dp[y1-1][x2]+dp[y1-1][x1-1])