import sys
from itertools import combinations
input = sys.stdin.readline

N = int(input())
populations =[0] + list(map(int, input().split()))
graph = [[]] + [list(map(int, input().split()))[1:] for _ in range(N)]

def dfs(s, m):
    stack = [s]
    visit[s] = m
    
    while stack:
        node = stack.pop()
        
        for n_node in graph[node]:
            if visit[n_node]: continue
            visit[n_node] = m
            stack.append(n_node)

visit = [0] * (N + 1)
mark = 0
for i in range(1, N + 1):
    if visit[i] == 0:
        mark += 1
        dfs(i, mark)

if mark >= 3:
    print(-1)
    sys.exit(0)

if mark == 2:
    scoreA, scoreB = 0, 0
    for i in range(1, N + 1):
        if visit[i] == mark: scoreB += populations[i]
        else: scoreA += populations[i]
    print(abs(scoreA - scoreB))
    sys.exit(0)

def check(zones):
    visit = [False] * (N + 1)
    visit[zones[0]] = True
    stack = [zones[0]]
    
    while stack:
        node = stack.pop()
        
        for n_node in graph[node]:
            if n_node not in zones: continue
            if visit[n_node]: continue
            visit[n_node] = True
            stack.append(n_node)
    
    for zone in zones:
        if not visit[zone]: return False

    return True

min_answer = float('inf')
all_zone = list(range(1, N + 1))
for r in range(1, N // 2 + 1):
    for zoneA in combinations(all_zone, r):
        zoneA = list(zoneA)
        zoneB = list(set(all_zone) - set(zoneA))
        if not check(zoneA) or not check(zoneB): continue
        
        scoreA = sum(populations[zone] for zone in zoneA)
        scoreB = sum(populations[zone] for zone in zoneB)
        min_answer = min(min_answer, abs(scoreA - scoreB))

print(min_answer)
