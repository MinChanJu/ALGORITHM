import sys
import heapq
input = sys.stdin.readline

N, M = map(int,input().split())
heap = []
entry = [0] * (N + 1)
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    A, B = map(int,input().split())
    entry[B] += 1
    graph[A].append(B)

for i in range(1, N + 1):
    if entry[i] == 0:
        heapq.heappush(heap, i)

while heap:
    student = heapq.heappop(heap)
    for i in graph[student]:
        entry[i] -= 1
        if entry[i] == 0:
            heapq.heappush(heap, i)
    print(student, end = ' ')