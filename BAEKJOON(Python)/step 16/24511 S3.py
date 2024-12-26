from collections import deque
n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
k=int(input())
C=list(map(int,input().split()))
ls=deque()
for i in range(n):
    if A[i]==0:
        ls.append(B[i])
for i in range(k):
    ls.appendleft(C[i])
    print(ls.pop(),end=" ")