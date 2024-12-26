import sys
from collections import deque
input=sys.stdin.readline

def sol(N,tree):
	q = deque([1])
	parent = [0] * (N+1)
	while q:
		now = q.popleft()
		for i in tree[now]:
			if parent[i] == 0 and i != 1:
				parent[i] = now
				q.append(i)
	for i in range(2,N+1):
		print(parent[i])

N=int(input())
dic={i:[] for i in range(1,N+1)}
for _ in range(N-1):
    a,b=map(int,input().split())
    dic[a].append(b)
    dic[b].append(a)
sol(N,dic)