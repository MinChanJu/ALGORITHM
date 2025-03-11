import sys
input = sys.stdin.readline

TC = int(input())
for i in range(TC):
    N, M = map(int,input().split())
    S = input().split()
    T = input().split()
    Q = int(input())
    answer = [f"#{i+1}"]
    for _ in range(Q):
        Y = int(input())
        answer.append(S[(Y-1)%N]+T[(Y-1)%M])
    print(*answer,sep=" ")