from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int,input().split())
ladder, snake = {i:0 for i in range(101)},{i:0 for i in range(101)}
for _ in range(N):
    x, y = map(int,input().split())
    ladder[x] = y   
for _ in range(M):
    u, v = map(int,input().split())
    snake[u] = v
queue = deque()
visit = [0 for _ in range(101)]
count = [0 for _ in range(101)]
queue.append(1)

while queue:
    node = queue.popleft()
    if node == 100:
        print(count[100])
        break
    for i in range(1,7):
        next = node + i
        if next <= 100 and visit[next] == 0:
            if ladder[next] != 0:
                next = ladder[next]
            elif snake[next] != 0:
                next = snake[next]
            if visit[next]==0:
                visit[next] = 1
                count[next] = count[node] + 1
                queue.append(next)