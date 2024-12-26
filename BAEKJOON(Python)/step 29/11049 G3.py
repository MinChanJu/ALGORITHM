import sys
input=sys.stdin.readline
N=int(input())
A=[]
for _ in range(N):
    A.append(list(map(int,input().split())))
    a=2**31
dp = [[a for _ in range(N)] for _ in range(N)]
for i in range(N):
    dp[i][i]=0
for i in range(1,N):
    for j in range(N-i):
        for k in range(j,j+i):
            s,m,e=j,k,j+i
            dp[s][e]=min(dp[s][e] , dp[s][m]+dp[m+1][e]+A[s][0]*A[m][1]*A[e][1])
print(dp[0][N-1])