import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())
country = {i: [] for i in range(1, N + 1)}
for _ in range(M):
    A, B, C = map(int, input().split())
    country[A].append((B, C))
    country[B].append((A, C))

factory_a, factory_b = map(int, input().split())

max_weight = [0] * (N + 1)
max_weight[factory_a] = 10 ** 9
heap = [(-10 ** 9, factory_a)]
while heap:
    weight, island = heapq.heappop(heap)
    weight *= -1
    if max_weight[island] > weight: continue
    if island == factory_b: break
    
    for next_island, next_weight in country[island]:
        next_weight = min(next_weight, weight)
        if max_weight[next_island] >= next_weight: continue
        
        max_weight[next_island] = next_weight
        heapq.heappush(heap, (-next_weight, next_island))

print(max_weight[factory_b])
