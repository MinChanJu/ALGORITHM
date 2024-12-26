import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, M = map(int,input().split())
    airplane = {i:[] for i in range(1,N+1)}
    for _ in range(M):
        a, b = map(int,input().split())
    print(N-1)