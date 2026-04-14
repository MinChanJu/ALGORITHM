import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())
mountain = {i: [] for i in range(1, N + 1)}
for _ in range(M):
    a, b, d = map(int, input().split())
    d *= 4
    mountain[a].append((d, b))
    mountain[b].append((d, a))

def solve(*speed):
    distance = [[float('inf')] * len(speed) for _ in range(N + 1)]
    distance[1][0] = 0
    heap = [(0, 0, 1)]
    
    while heap:
        time, cnt, node = heapq.heappop(heap)
        if time != distance[node][cnt]: continue
        
        for dist, n_node in mountain[node]:
            n_time = time + (dist // speed[cnt])
            n_cnt = (cnt + 1) % len(speed)
            if n_time >= distance[n_node][n_cnt]: continue
            distance[n_node][n_cnt] = n_time
            heapq.heappush(heap, (n_time, n_cnt, n_node))
    
    return distance

fox = solve(2)
wolf = solve(4, 1)

cnt = 0
for i in range(1, N + 1):
    fox_i = min(fox[i])
    wolf_i = min(wolf[i])
    if fox_i < wolf_i: cnt += 1

print(f"Fox: {fox}")
print(f"Wolf: {wolf}")
print(cnt)
