import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int,input().split())
    r3=((x2-x1)**2+(y2-y1)**2)**0.5
    if x1==x2 and y1==y2 and r1==r2:
        print(-1)
    elif r3<r1 and r1>r2:
        if r3+r2 > r1:
            print(2)
        elif r3+r2 == r1:
            print(1)
        elif r3+r2 < r1:
            print(0)
    elif r3<r2 and r1<r2:
        if r3+r1 > r2:
            print(2)
        elif r3+r1 == r2:
            print(1)
        elif r3+r1 < r2:
            print(0)
    elif r3 > r1+r2:
        print(0)
    elif r3 == r1+r2:
        print(1)
    elif r3 < r1+r2:
        print(2)