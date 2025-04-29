import heapq
import sys
input = sys.stdin.readline

N, K = map(int,input().split())
jewel = []
bag = []
for _ in range(N):
    M, V = map(int, input().split())
    heapq.heappush(jewel, (M, V))

for _ in range(K):
    heapq.heappush(bag, int(input()))

sum = 0
capable = []
for _ in range(K):
    bagc = heapq.heappop(bag)
    while jewel and bagc >= jewel[0][0]:
        w, v = heapq.heappop(jewel)
        heapq.heappush(capable, -v)
    if capable:
        sum -= heapq.heappop(capable)
    elif not jewel:
        break

print(sum)