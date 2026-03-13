from collections import deque
import sys
input = sys.stdin.readline

N, K = map(int, input().split())

if N >= K:
    print(N - K)
    print(1)
    sys.exit(0)

find_dist = [float("inf"), 0]

max_pos = K + 2
visit = [-1 for _ in range(max_pos)]
visit[N] = 0
queue = deque([N])
while queue:
    node = queue.popleft()
    if node == K:
        if find_dist[0] < visit[node]: continue
        if find_dist[0] > visit[node]: find_dist = [visit[node], 0]
        find_dist[1] += 1
        continue
    
    if visit[node] > find_dist[0]: break
    
    for next_node in [node - 1, node + 1, node * 2]:
        if next_node >= max_pos or next_node < 0: continue
        if visit[next_node] != -1 and visit[next_node] < visit[node] + 1: continue
        visit[next_node] = visit[node] + 1
        queue.append(next_node)

print(*find_dist, sep="\n")
