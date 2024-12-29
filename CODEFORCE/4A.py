import sys
input = sys.stdin.readline

W = int(input())
if (W <= 2): print("NO")
else:
    if ((W-2)%2 == 0): print("YES")
    else: print("NO")