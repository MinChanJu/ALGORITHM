import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int,input().split()))
dp = [[1,A[i]] for i in range(N)]
dp[0] = [1,A[0]]
for i in range(1,N):
    for j in range(i):
        if dp[j][-1] < A[i] and dp[i][0] <= dp[j][0]:
            dp[i] = dp[j][0:] + [A[i]]
            dp[i][0] += 1
s = 0
for i in range(1,N):
    if dp[i][0]>dp[s][0]:
        s = i
print(dp[s][0])
print(*dp[s][1:])