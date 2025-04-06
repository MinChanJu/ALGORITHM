from functools import cmp_to_key
import sys
input = sys.stdin.readline

answer = []
T = int(input())
for _ in range(T):
    n = int(input())
    t = list(map(int,input().split()))
    
    tier = {}
    for i in range(n): tier[t[i]] = i+1
    
    m = int(input())
    graph = {i:[] for i in range(1, n+1)}
    for i in range(m):
        a, b = map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)
        
    def compare_students(a, b):
        global graph, tier
        if b in graph[a]: return tier[b] - tier[a]
        else: return tier[a] - tier[b]
    
    t.sort(key=cmp_to_key(compare_students))
    
    check = True
    for i in range(n):
        for j in range(i+1, n):
            if (tier[t[i]] > tier[t[j]]):
                if (t[j] not in graph[t[i]]):
                    check = False
                    answer.append("IMPOSSIBLE")
                    break
        if (not check): break
                    
    if (check):
        res = ""
        for i in range(n):
            res += str(t[i])
            if (i != n-1): res += " "
        answer.append(res)

print(*answer, sep="\n")