import sys
input = sys.stdin.readline

INF = 1e9
def dfs(worker, work):
    global N, dp, D
    if worker == N:
        return 0
    if dp[worker][work] != -1:
        return dp[worker][work]
    dp[worker][work] = INF
    for i in range(N):
        if work & (1 << i):
            continue
        next_work = work | (1 << i)
        dp[worker][work] = min(dp[worker][work], dfs(worker+1, next_work) + D[worker][i])
    return dp[worker][work]

N = int(input())
D = [list(map(int, input().split())) for _ in range(N)]
dp = [[-1 for _ in range(1 << N)] for _ in range(N)]
result = dfs(0, 0)
print(result)