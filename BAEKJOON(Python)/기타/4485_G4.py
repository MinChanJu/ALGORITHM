import sys
import heapq
input = sys.stdin.readline

answers =[]

tc = 1
while True:
    N = int(input())
    if N == 0: break

    cave = [list(map(int, input().split())) for _ in range(N)]

    visit = [[20 * N] * N for _ in range(N)]
    visit[0][0] = cave[0][0]

    heap = [(visit[0][0], 0, 0)]
    while heap:
        rupee, i, j = heapq.heappop(heap)
        if rupee > visit[i][j]: continue
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = i + dx, j + dy
            if ni < 0 or nj < 0: continue
            if ni >= N or nj >= N: continue
            
            if visit[ni][nj] <= rupee + cave[ni][nj]: continue
            visit[ni][nj] = rupee + cave[ni][nj]
            heapq.heappush(heap, (visit[ni][nj], ni, nj))
    
    answers.append(f"Problem {tc}: {visit[N-1][N-1]}")
    
    tc += 1

print(*answers, sep="\n")
