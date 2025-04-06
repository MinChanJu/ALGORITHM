from collections import deque
import sys
input = sys.stdin.readline

N, K = map(int, input().split())

def BFS(K):
    visit = [False for _ in range(200001)]
    queue = deque()
    queue.append((K, 0))
    visit[K] = True
    while queue:
        node, count = queue.popleft()
        if node == N:
            break
        if count >= abs(N - K):
            count = abs(N - K)
            break
        if not (node % 2) and not visit[node//2]:
            visit[node//2] = True
            queue.append((node//2, count))
        if not visit[node + 1]:
            visit[node + 1] = True
            queue.append((node+1, count + 1))
        if not visit[node -1]:
            visit[node - 1] = True
            queue.append((node-1, count + 1))
    return count

print(BFS(K))