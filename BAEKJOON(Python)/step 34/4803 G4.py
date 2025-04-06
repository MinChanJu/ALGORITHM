import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e6))

def is_cycle(x, prev):
	visit[x] = 1
	for y in graph[x]:
		if visit[y]:
			if y != prev: return 1
		elif is_cycle(y, x): return 1
	return 0

T = 1
while 1:
	n, m = map(int, input().split())
	if n == 0 and m == 0: break
	graph = [[] for _ in range(n+1)]
	visit = [0] * (n+1)
	for i in range(m):
		a , b = map(int , input().split())
		graph[a].append(b)
		graph[b].append(a)
	cnt = 0
	for i in range(1 , n+1):
		if not visit[i] and not is_cycle(i,0): cnt += 1
	if cnt == 0: print("Case %d: No trees."%(T))
	elif cnt == 1: print("Case %d: There is one tree."%(T))
	else: print("Case %d: A forest of %d trees."%(T, cnt))
	T += 1