from collections import deque
import sys
input = sys.stdin.readline

answer = []
T = int(input())
for _ in range(T):
    n = int(input())
    t = list(map(int, input().split()))
    
    indegree = [0] * (n + 1)
    graph = [[False] * (n + 1) for _ in range(n + 1)]
    
    for i in range(n):
        for j in range(i + 1, n):
            graph[t[i]][t[j]] = True
            indegree[t[j]] += 1
    
    m = int(input())
    for _ in range(m):
        a, b = map(int, input().split())
        if graph[a][b]:
            graph[a][b] = False
            graph[b][a] = True
            indegree[b] -= 1
            indegree[a] += 1
        else:
            graph[b][a] = False
            graph[a][b] = True
            indegree[a] -= 1
            indegree[b] += 1
    
    result = []
    q = deque()

    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)

    certain = True
    cycle = False

    for _ in range(n):
        if len(q) == 0:
            cycle = True
            break
        if len(q) > 1:
            certain = False
            break
        now = q.popleft()
        result.append(now)
        for i in range(1, n + 1):
            if graph[now][i]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    q.append(i)

    if cycle or not certain:
        answer.append("IMPOSSIBLE")
    else:
        answer.append(' '.join(map(str, result)))
print(*answer, sep="\n")