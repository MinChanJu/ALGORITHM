import sys
input = sys.stdin.readline

N, S = map(int,input().split())
A = list(map(int,input().split()))

s = 0
e = 0
SUM = A[0]
result = N+1
while e < N:
    if SUM >= S:
        result = min(result,e-s+1)
        SUM -= A[s]
        s += 1
    else:
        e += 1
        if e < N:
            SUM += A[e]
if result == N+1:
    print(0)
else:
    print(result)