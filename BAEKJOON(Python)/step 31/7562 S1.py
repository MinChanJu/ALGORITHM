from collections import deque
import sys
input = sys.stdin.readline

def bfs(R):
    global count
    visit[R[0]*l+R[1]] = 0
    queue.append(R)
    while queue:
        node = queue.popleft()
        if node == (future_x,future_y):
            print(visit[node[0]*l+node[1]])
            break
        if node[0]+2<l and node[1]+1<l and visit[(node[0]+2)*l+node[1]+1] ==-1:
            queue.append((node[0]+2,node[1]+1))
            visit[(node[0]+2)*l+node[1]+1] = visit[node[0]*l+node[1]]+1
        if node[0]+1<l and node[1]+2<l and visit[(node[0]+1)*l+node[1]+2] ==-1:
            queue.append((node[0]+1,node[1]+2))
            visit[(node[0]+1)*l+node[1]+2] = visit[node[0]*l+node[1]]+1
        if node[0]+2<l and node[1]-1>=0 and visit[(node[0]+2)*l+node[1]-1] ==-1:
            queue.append((node[0]+2,node[1]-1))
            visit[(node[0]+2)*l+node[1]-1] = visit[node[0]*l+node[1]]+1
        if node[0]+1<l and node[1]-2>=0 and visit[(node[0]+1)*l+node[1]-2] ==-1:
            queue.append((node[0]+1,node[1]-2))
            visit[(node[0]+1)*l+node[1]-2] = visit[node[0]*l+node[1]]+1
        if node[0]-2>=0 and node[1]+1<l and visit[(node[0]-2)*l+node[1]+1] ==-1:
            queue.append((node[0]-2,node[1]+1))
            visit[(node[0]-2)*l+node[1]+1] = visit[node[0]*l+node[1]]+1
        if node[0]-1>=0 and node[1]+2<l and visit[(node[0]-1)*l+node[1]+2] ==-1:
            queue.append((node[0]-1,node[1]+2))
            visit[(node[0]-1)*l+node[1]+2] = visit[node[0]*l+node[1]]+1
        if node[0]-2>=0 and node[1]-1>=0 and visit[(node[0]-2)*l+node[1]-1] ==-1:
            queue.append((node[0]-2,node[1]-1))
            visit[(node[0]-2)*l+node[1]-1] = visit[node[0]*l+node[1]]+1
        if node[0]-1>=0 and node[1]-2>=0 and visit[(node[0]-1)*l+node[1]-2] ==-1:
            queue.append((node[0]-1,node[1]-2))
            visit[(node[0]-1)*l+node[1]-2] = visit[node[0]*l+node[1]]+1

T = int(input())
for _ in range(T):
    l = int(input())
    current_x, current_y = map(int,input().split())
    future_x, future_y = map(int,input().split())
    visit = [-1 for _ in range(l*l)]
    queue = deque()
    bfs((current_x,current_y))