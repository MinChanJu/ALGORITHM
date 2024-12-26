import sys
input=sys.stdin.readline

N,M = map(int,input().split())
memory = list(map(int,input().split()))
cost = list(map(int,input().split()))

dp = [[0 for i in range(N+1)]]
need_cost = -1

while(max(dp[need_cost]) < M):
    dp.append([0 for i in range(N+1)])
    need_cost += 1
    
    for i in range(N):
        if cost[i] <= need_cost:
            dp[need_cost][i+1] = max(dp[need_cost - cost[i]][i] + memory[i],dp[need_cost][i])
        else:
            dp[need_cost][i+1] = dp[need_cost][i]
print(need_cost)