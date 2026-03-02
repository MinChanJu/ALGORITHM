import sys
input = sys.stdin.readline

N = int(input())
graph = {i: int(input()) for i in range(1, N+1)}

def dfs(s):
    visited = [False] * (N+1)
    visited[s] = True
    node = s
    while True:
        next_node = graph[node]
        if visited[next_node]:
            break
        visited[next_node] = True
        node = next_node
    
    if next_node != s:
        return []
    else:
        return [i for i in range(1, N+1) if visited[i]]
    
answer = []
for i in range(1, N+1):
    if i in answer: continue
    
    cycle = dfs(i)
    answer += cycle

print(len(answer))
answer.sort()
print(*answer, sep="\n")