import heapq
import sys
input = sys.stdin.readline

def prim(road,start):
    visit = set([start])
    mst = []
    edge = [(distance, start, end) for end, distance in road[start]]
    heapq.heapify(edge)
    while edge:
        dis, u, v = heapq.heappop(edge)
        if v not in visit:
            visit.add(v)
            mst.append((u,v,dis))
            for end, distance in road[v]:
                if end not in visit:
                    heapq.heappush(edge,(distance,v,end))
    return mst

while 1:
    m, n = map(int,input().split())
    if m == 0 and n == 0: break
    road = {i:[] for i in range(m)}
    sum = 0
    for _ in range(n):
        x, y ,z = map(int,input().split())
        road[x].append((y,z))
        road[y].append((x,z))
        sum += z
    mst = prim(road,0)
    val = 0
    for edge in mst:
        val += edge[2]
    print(sum-val)