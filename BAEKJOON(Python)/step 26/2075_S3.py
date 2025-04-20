import sys
import heapq
input = sys.stdin.readline

N = int(input())

total = []
for _ in range(N):
  ls = list(map(int, input().split()))
  for i in ls:
    heapq.heappush(total, i)
    if (len(total) > N):
      heapq.heappop(total)

print(heapq.heappop(total))