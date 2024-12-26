from collections import deque
import heapq
import sys
input = sys.stdin.readline

def bfs(s,num):
    visit = [0 for i in range(N*M)]
    queue = deque()
    queue.append(s)
    map_O[s//M][s%M] = num
    while queue:
        m = queue.pop()
        i = m//M
        j = m%M
        for x,y in [(0,1),(1,0),(-1,0),(0,-1)]:
            next_i = i+x
            next_j = j+y
            if 0<=next_i<N and 0<=next_j<M:
                if map_O[next_i][next_j] == 1 and visit[next_i*M+next_j] == 0:
                    map_O[next_i][next_j] = num
                    queue.append(next_i*M+next_j)
                    visit[next_i*M+next_j] = 1
    return

def prim(graph,start):
    visit = set([start])
    mst = []
    edge = [(d,start,i) for i,d in graph[start]]
    heapq.heapify(edge)
    while edge:
        dis, u, v = heapq.heappop(edge)
        if v not in visit:
            visit.add(v)
            mst.append((u,v,dis))
            for end,d in graph[v]:
                if end not in visit:
                    heapq.heappush(edge,(d,v,end))
    return mst,visit

N, M = map(int,input().split())
map_O = []
for _ in range(N):
    ls = list(map(int,input().split()))
    map_O.append(ls)
num = 2
for i in range(N):
    for j in range(M):
        if map_O[i][j] == 1:
            bfs(i*M+j,num)
            num += 1
map_T = [[map_O[i][j] for i in range(N)] for j in range(M)]
bridge = {i:{j:0 for j in range(2,num)} for i in range(2,num)}
for i in range(N):
    s = -1
    k = 0
    for j in range(M):
        if map_O[i][j] != 0:
            if k == 0:
                k = map_O[i][j]
                s = j
            elif s == j-1:
                s = j
            else:
                if k == map_O[i][j]:
                    s = j
                    continue
                elif j-s > 2:
                    if bridge[k][map_O[i][j]] == 0:
                        bridge[k][map_O[i][j]] = j-s-1
                        bridge[map_O[i][j]][k] = j-s-1
                    else:
                        bridge[k][map_O[i][j]] = min(bridge[k][map_O[i][j]],j-s-1)
                        bridge[map_O[i][j]][k] = min(bridge[map_O[i][j]][k],j-s-1)
                s = j
                k = map_O[i][j]
for i in range(M):
    s = -1
    k = 0
    for j in range(N):
        if map_T[i][j] != 0:
            if k == 0:
                k = map_T[i][j]
                s = j
            elif s == j-1:
                s = j
            else:
                if k == map_T[i][j]:
                    s = j
                    continue
                elif j-s > 2:
                    if bridge[k][map_T[i][j]] == 0:
                        bridge[k][map_T[i][j]] = j-s-1
                        bridge[map_T[i][j]][k] = j-s-1
                    else:
                        bridge[k][map_T[i][j]] = min(bridge[k][map_T[i][j]],j-s-1)
                        bridge[map_T[i][j]][k] = min(bridge[map_T[i][j]][k],j-s-1)
                s = j
                k = map_T[i][j]
graph = {i:[] for i in range(2,num)}
for i in range(2,num):
    for j in range(i+1,num):
        if bridge[i][j]!=0:
            graph[i].append((j,bridge[i][j]))
            graph[j].append((i,bridge[i][j]))
mst, visit = prim(graph,2)
val = 0
for edge in mst:
    val += edge[2]
if len(visit) != num-2:
    print(-1)
else:
    print(val)