import sys
input=sys.stdin.readline
N, M, K = map(int, input().split())
ch = []
for _ in range(N):
    lk = list(input().strip())
    ls = []
    for i in lk:
        if i == "B":
            ls.append(1)
        else:
            ls.append(0)
    ch.append(ls)
def mc(c):
    dp = [[0 for _ in range(M+1)] for _ in range(N+1)]
    for i in range(N):
        for j in range(M):
            if not ((i + j) % 2):
                v = ch[i][j] != c
            else:
                v = ch[i][j] == c
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + v
    r = N * M + 1
    for i in range(1, N-K+2):
        for j in range(1, M-K+2):
            t = dp[i+K-1][j+K-1] - dp[i+K-1][j-1] - dp[i-1][j+K-1] + dp[i-1][j-1]
            r = min(r, t)
    return r
print(min(mc(0), mc(1)))