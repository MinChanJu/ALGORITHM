from collections import deque
import sys
input = sys.stdin.readline

N = int(input())

visit = [[0]]*(N+1)
queue = deque()
queue.append(N)
visit[N] = [0,N]
while queue:
    node = queue.popleft()
    if node == 1:
        break
    if visit[node//3][0] == 0 and node%3 == 0:
        visit[node//3] = visit[node][0:]
        visit[node//3][0] += 1
        visit[node//3].append(node//3)
        queue.append(node//3)
    if visit[node//2][0] == 0 and node%2 == 0:
        visit[node//2] = visit[node][0:]
        visit[node//2][0] += 1
        visit[node//2].append(node//2)
        queue.append(node//2)
    if visit[node-1][0] == 0 and node-1 > 0:
        visit[node-1] = visit[node][0:]
        visit[node-1][0] += 1
        visit[node-1].append(node-1)
        queue.append(node-1)
print(visit[node][0])
for i in range(1,visit[node][0]+2):
    print(visit[node][i], end=' ')