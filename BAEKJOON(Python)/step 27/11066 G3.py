import sys
input=sys.stdin.readline
T=int(input())
for _ in range(T):
    K=int(input())
    pages = list(map(int, input().split()))
    dp = [[0 for _ in range(K)] for _ in range(K)]
    for i in range(1, K):
        for j in range(K):
            end = j + i
            if end >= K: 
                break
            dp[j][end] = 9999999999
            page_sum = sum(pages[j:end+1])
            for k in range(j, end):
                dp[j][end] = min(dp[j][end], dp[j][k] + dp[k+1][end] + page_sum)
    print(dp[0][K-1])