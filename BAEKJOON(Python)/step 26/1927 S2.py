import heapq
import sys
input=sys.stdin.readline
N=int(input())
A=[]
for _ in range(N):
    k=int(input())
    if k==0:
        if A:
            print(heapq.heappop(A))
        else:
            print(0)
    else:
        heapq.heappush(A,k)