import heapq
import sys
input = sys.stdin.readline

def prim(star, start):
    mst = []
    visit = set([start])
    edges = []
    for i in range(n):
        if i == start: continue
        weight = ((star[start][0]-star[i][0])**2 + (star[start][1]-star[i][1])**2)**(1/2)
        edges.append((weight,start,i))
    heapq.heapify(edges)
    while edges:
        weight, u, v = heapq.heappop(edges)
        if v not in visit:
            visit.add(v)
            mst.append((u, v, weight))
            for next in range(n):
                if next == v: continue
                weight = ((star[v][0]-star[next][0])**2 + (star[v][1]-star[next][1])**2)**(1/2)
                if next not in visit:
                    heapq.heappush(edges, (weight, v, next))
    return mst

n = int(input())
star = []
for _ in range(n):
    x, y = map(float,input().split())
    star.append((x,y))


mst = prim(star,0)
val = 0
for edge in mst:
    val += edge[2]
print("{:.2f}".format(val))