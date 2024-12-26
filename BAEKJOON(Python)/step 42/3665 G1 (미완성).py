import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    t = list(map(int,input().split()))
    m = int(input())
    order = []
    for i in range(m):
        a, b = map(int,input().split())
        order.append((a,b))