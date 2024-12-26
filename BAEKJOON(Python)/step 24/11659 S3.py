import sys
input = sys.stdin.readline

N, M = map(int,input().split())
ls = list(map(int,input().split()))

prefix_sum = [0 for _ in range(N+1)]
for i in range(1,N+1):
    prefix_sum[i] = prefix_sum[i-1] + ls[i-1]

for k in range(M):
    i, j = map(int,input().split())
    print(prefix_sum[j] - prefix_sum[i-1])