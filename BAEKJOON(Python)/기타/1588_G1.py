import sys
input = sys.stdin.readline

trans = {
    1: [1, 3, 2],
    2: [2, 1, 1],
    3: [2, 3, 2]
}

sequence = int(input())
left = int(input())
right = int(input())
N = int(input())

dp = [[[0] * 3 for _ in range(N + 1)] for _ in range(4)]
for i in  range(1, 4):
    dp[i][0][i - 1] = 1

for t in range(1, N + 1):
    for x in range(1, 4):
        a, b, c = trans[x]
        for i in range(3):
            dp[x][t][i] = dp[a][t - 1][i] + dp[b][t - 1][i] + dp[c][t - 1][i]

count = [0, 0, 0]
def solve(s, k, l, r):
    if r < left or right < l:
        return

    if left <= l and r <= right:
        for i in range(3):
            count[i] += dp[s][k][i]
        return

    if k == 0:
        count[s - 1] += 1
        return

    block = 3 ** (k - 1)
    a, b, c = trans[s]

    solve(a, k - 1, l, l + block - 1)
    solve(b, k - 1, l + block, l + 2 * block - 1)
    solve(c, k - 1, l + 2 * block, r)

solve(sequence, N, 0, 3 ** N - 1)
print(*count)
