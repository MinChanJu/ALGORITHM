from math import gcd, factorial
import sys
input = sys.stdin.readline

def dfs(num_len, visited, remainder):
    if visited == (1 << N) - 1:
        if not remainder:
            return 1
        else:
            return 0
    if dp[visited][remainder] != -1:
        return dp[visited][remainder]
    for i in range(N):
        if not visited & (1 << i):
            dp[visited][remainder] += dfs(num_len + length[i], visited|(1 << i), 
                                        (remainder + remainders[i][num_len]) % K)
    dp[visited][remainder] += 1
    return dp[visited][remainder]

N = int(input())
seq = []
for _ in range(N):
    seq.append(int(input()))
length = []
for num in seq:
    length.append(len(str(num)))
K = int(input())
dp = [[-1 for _ in range(K)] for _ in range(1 << N)]
remainders = [[-1 for _ in range(sum(length))] for _ in range(N)]
for i in range(N):
    for j in range(sum(length)):
        remainders[i][j] = (10 ** j * seq[i]) % K
result = dfs(0, 0, 0)
f = factorial(N)
if not result:
    print("0/1") 
else:
    div = gcd(f, dp[0][0])
    print(f"{result//div}/{f//div}")