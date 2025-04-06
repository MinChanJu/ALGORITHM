import heapq
import sys
input=sys.stdin.readline
N=int(input())
A=[]
for _ in range(N):
    k=int(input())
    if k==0:
        if A:
            s=heapq.heappop(A)
            print(s[0]*s[-1])
        else:
            print(0)
    else:
        if k<0:
            heapq.heappush(A,(-1*k,-1))
        else:
            heapq.heappush(A,(k,1))