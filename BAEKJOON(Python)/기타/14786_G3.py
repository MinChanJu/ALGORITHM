import sys
from math import sin
input = sys.stdin.readline

error = 1e-9
A, B, C = map(int, input().split())
s, e = (C - B) / A, (C + B) / A

while s <= e:
    mid = (s + e) / 2
    result = A * mid + B * sin(mid) - C
    if result > error: e = mid - error
    elif result < -error: s = mid + error
    else: break

print(e)
