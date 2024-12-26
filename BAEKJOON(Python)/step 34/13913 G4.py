from collections import deque
import sys
input = sys.stdin.readline

def get_path(end):
    path = []
    now = end
    for _ in range(visit[end] + 1):
        path.append(now)
        now = count[now]
    path.reverse()
    print(*path)

N, K = map(int, input().split())
queue = deque()
visit = [0] * 100001
count = [0] * 100001

queue.append(N)
while queue:
    node = queue.popleft()
    if node == K:
        print(visit[node])
        get_path(node)
        break
    if 0 <= node+1 <= 100000 and visit[node+1] == 0:
        queue.append(node+1)
        visit[node+1] = visit[node] + 1
        count[node+1] = node
    if 0 <= node-1 <= 100000 and visit[node-1] == 0:
        queue.append(node-1)
        visit[node-1] = visit[node] + 1
        count[node-1] = node
    if 0 <= 2*node <= 100000 and visit[2*node] == 0:
        queue.append(2*node)
        visit[2*node] = visit[node] + 1
        count[2*node] = node