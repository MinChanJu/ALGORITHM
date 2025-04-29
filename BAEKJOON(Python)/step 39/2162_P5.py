from collections import deque
import sys
input = sys.stdin.readline

def ccw(p1,p2,p3):
    direction = p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p1[1] - (p2[0]*p1[1] + p3[0]*p2[1] + p1[0]*p3[1])
    if direction > 0: return 1
    elif direction < 0: return -1
    else: return 0

def check(A,B):
    p1, p2, p3, p4 = A[0], A[1], B[0], B[1]
    x1, y1 = p1[0], p1[1]
    x2, y2 = p2[0], p2[1]
    x3, y3 = p3[0], p3[1]
    x4, y4 = p4[0], p4[1]
    ccw1 = ccw(p1, p2, p3) * ccw(p1, p2, p4)
    ccw2 = ccw(p3, p4, p1) * ccw(p3, p4, p2)

    if not ccw1 and not ccw2:
        if min(x1, x2) <= max(x3, x4) and max(x1, x2) >= min(x3, x4) and min(y1, y2) <= max(y3, y4) and max(y1, y2) >= min(y3, y4): return 1
        else: return 0
    elif ccw1 <= 0 and ccw2 <= 0: return 1
    else: return 0

def BFS(start, graph, cnt):
    queue = deque()
    queue.append(start)
    visit[start] = cnt
    p = 0
    while queue:
        node = queue.popleft()
        p += 1
        for n_node in graph[node]:
            if visit[n_node] == 0:
                visit[n_node] = cnt
                queue.append(n_node)
    return p

N = int(input())
point = [[(0,0),(0,0)]]
for _ in range(N):
    x1, y1, x2, y2 = map(int,input().split())
    point.append([(x1, y1), (x2, y2)])
graph = {i:[] for i in range(1,N+1)}
for  i in range(1,N+1):
    for j in range(i+1,N+1):
        if check(point[i],point[j]):
            graph[i].append(j)
            graph[j].append(i)

visit = [0]*(N+1)
cnt, M = 0, 0
for i in range(1,N+1):
    if visit[i] == 0:
        cnt += 1
        p = BFS(i,graph,cnt)
        if p > M: M = p
print(cnt)
print(M)