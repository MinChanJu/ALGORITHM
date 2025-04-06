import sys
input = sys.stdin.readline

N, K = map(int,input().split())
ls = list(map(int,input().split()))

prefix_sum = [0 for _ in range(N-K+1)]
for i in range(K):
    prefix_sum[0] += ls[i]

for i in range(1, N-K+1):
    prefix_sum[i] = prefix_sum[i-1] - ls[i-1] + ls[i+K-1]

print(max(prefix_sum))