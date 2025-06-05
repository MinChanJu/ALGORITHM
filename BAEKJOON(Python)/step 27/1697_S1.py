from collections import deque
import sys
input = sys.stdin.readline

N, K = map(int,input().split())

visit = [-1 for _ in range(100001)]
queue = deque()
queue.append(N)
visit[N] = 0
while queue:
    node = queue.popleft()
    if node == K:
        print(visit[node])
        break
    if node+1 <= 100000 and visit[node+1] == -1:
        visit[node+1] = visit[node] + 1
        queue.append(node+1)
    if node-1 >= 0 and visit[node-1] == -1:
        visit[node-1] = visit[node] + 1
        queue.append(node-1)
    if node*2 <= 100000 and visit[node*2] == -1:
        visit[node*2] = visit[node] + 1
        queue.append(node*2)