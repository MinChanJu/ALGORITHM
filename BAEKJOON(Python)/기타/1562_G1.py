import sys
input = sys.stdin.readline

P = 1_000_000_000
N = int(input())

dp = [[[0] * 2 ** 10 for _ in range(10)] for _ in range(N+1)]
for i in range(1, 10):
    dp[1][i][1 << i] = 1

for n in range(2, N+1):
    for i in range(10):
        for bit in range(2**10):
            last_bit = 1 << i
            if bit & last_bit == 0: continue
            if i > 0:
                dp[n][i][bit] += dp[n-1][i-1][bit & ~last_bit]
                dp[n][i][bit] += dp[n-1][i-1][bit]
            if i < 9:
                dp[n][i][bit] += dp[n-1][i+1][bit & ~last_bit]
                dp[n][i][bit] += dp[n-1][i+1][bit]
            dp[n][i][bit] %= P

cnt = 0
for i in range(10):
    cnt += dp[N][i][2**10 -1]

print(cnt % P)
