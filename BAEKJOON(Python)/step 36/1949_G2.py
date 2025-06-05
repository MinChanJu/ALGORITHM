import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

N = int(input())
people = [0] + list(map(int,input().split()))
graph = {i:[] for i in range(1,N+1)}
for _ in range(N-1):
    u, v = map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)

dp = [[0,people[i]] for i in range(N+1)]
visit = [0]*(N+1)

def dfs(node):
    visit[node] = 1
    for n_node in graph[node]:
        if visit[n_node] == 0:
            dfs(n_node)
            dp[node][0] += max(dp[n_node][0],dp[n_node][1])
            dp[node][1] += dp[n_node][0]

dfs(1)
print(max(dp[1][0],dp[1][1]))