import heapq
import sys
input = sys.stdin.readline

def dijkstra(graph,s):
    visit = [500000000 for i in range(n+1) ]
    visit[s] = 0
    queue = []
    heapq.heappush(queue,(0,s))
    while queue:
        cost, node = heapq.heappop(queue)
        if visit[node] < cost: continue
        for n_node, n_cost in graph[node]:
            next = cost + n_cost    
            if visit[n_node] > next:
                visit[n_node] = next
                heapq.heappush(queue,(next,n_node))
    return visit

T = int(input())
for _ in range(T):
    n,m,t = map(int,input().split())
    s,g,h = map(int,input().split())
    graph0 = [[] for i in range(n+1)]
    graph1 = [[] for i in range(n+1)]
    end = []
    
    for i in range(m):
        u,v,w = map(int,input().split())
        graph0[u].append([v,w])
        graph0[v].append([u,w])
        if set([g,h]) == set([u,v]):
            road = w
            continue
        graph1[u].append([v,w])
        graph1[v].append([u,w])
    for i in range(t):
        end.append(int(input()))
    end.sort()
        
    case1 = dijkstra(graph0,s)
    case2 = dijkstra(graph1,s)
    for c in end:
        if case1[c] < case2[c]:
            print(c,end=' ')
        elif case1[c] == case2[c]:
            test = dijkstra(graph0,c)
            ex1 = case1[g] + road + test[h]
            ex2 = case1[h] + road + test[g]
            ex0 = min(ex1,ex2)
            if ex0 == case1[c]:
                print(c,end=' ')
    print('')

# import heapq
# import sys
# input = sys.stdin.readline

# def dikstra(start,end,graph,n):
#     queue = []
#     heapq.heappush(queue, (0,start))
#     visit = [500000000 for _ in range(n+1)]
#     visit[s] = 0
#     while queue:
#         cost, node = heapq.heappop(queue)
#         if visit[node] < cost:
#             continue
#         for n_cost, n_node in graph[node]:
#             if n_cost+cost < visit[n_node]:
#                 visit[n_node] = n_cost + cost
#                 heapq.heappush(queue, (n_cost+cost, n_node))
#     return visit[end]

# T = int(input())
# for _ in range(T):
#     n, m, t = map(int,input().split())
#     s, g, h = map(int,input().split())
#     graph = {i:[] for i in range(1,n+1)}
#     for _ in range(m):
#         T, b, d = map(int,input().split())
#         graph[T].append((d,b))
#         graph[b].append((d,T))
#     end = []
#     for _ in range(t):
#         end.append(int(input()))
#     end.sort()
#     s_g = dikstra(s,g,graph,n)
#     s_h = dikstra(s,h,graph,n)
#     h_g = dikstra(h,g,graph,n)
#     g_h = dikstra(g,h,graph,n)
#     for node in end:
#         g_end = dikstra(g,node,graph,n)
#         h_end = dikstra(h,node,graph,n)
#         s_end = dikstra(s,node,graph,n)
#         if s_g + g_h + h_end == s_end:
#             print(node, end=' ')
#         elif s_h + h_g + g_end == s_end:
#             print(node, end=' ')
#     print('')