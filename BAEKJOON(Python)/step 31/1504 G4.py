import heapq
import sys
input = sys.stdin.readline

V, E = map(int,input().split())
graph = {i:[] for i in range(1,V+1)}
for _ in range(E):
    a,b,c = map(int,input().split())
    graph[a].append((c,b))
    graph[b].append((c,a))
u, v = map(int,input().split())

def dikstra(s,e):
    visit = [2000000000]*(V+1)
    visit[s] = 0
    heap = []
    heapq.heappush(heap,(0,s))
    while heap:
        cost, node = heapq.heappop(heap)
        if visit[node] < cost:
            continue
        for dis, n_node in graph[node]:
            if dis+cost < visit[n_node]:
                visit[n_node]=dis+cost
                heapq.heappush(heap,(dis+cost,n_node))
    return visit[e]

one_u = dikstra(1,u)
one_v = dikstra(1,v)
u_v = dikstra(u,v)
v_u = dikstra(v,u)
u_end = dikstra(u,V)
v_end = dikstra(v,V)

if one_u != 2000000000 and u_v != 2000000000 and v_end != 2000000000:
    count = one_u + u_v + v_end
else:
    count = -1

if one_v != 2000000000 and v_u != 2000000000 and u_end != 2000000000:
    if count > one_v + v_u + u_end:
        count = one_v + v_u + u_end
else:
    count = -1

print(count)