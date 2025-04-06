import sys
input = sys.stdin.readline

N, M = map(int,input().split())

graph = {i:[[0,0]] for i in range(1,N+1)}
for _ in range(M):
    A, B = map(int,input().split())
    graph[A][0][0] += 1
    graph[B][0][1] += 1
    graph[A].append(B)

s = []
for i in range(1,N+1):
    if graph[i][0][1] == 0:
        s.append(i)

result = []
while s:
    p = s.pop()
    result.append(p)
    for num in graph[p][1:]:
        graph[num][0][1] -= 1
        if graph[num][0][1] == 0:
            s.append(num)

print(*result, sep=" ")