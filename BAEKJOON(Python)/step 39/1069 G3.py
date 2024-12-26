import sys
input = sys.stdin.readline

X, Y, D, T = map(int,input().split())
d = (X**2 + Y**2)**(1/2)

if D > d:
    time = min(d, T * 2, T + D - d)
else:
    cnt = d//D
    time = min(d, (T - D) * cnt + d, T * (cnt + 1))
print(time)

