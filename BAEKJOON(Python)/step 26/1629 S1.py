import sys
input=sys.stdin.readline
A, B, C = map(int, input().split())
def square(B):
    global A, C
    if B == 1:
        return A%C
    t=square(B//2)
    if B%2:
        return (t*t*A)%C
    else:
        return (t*t)%C 
print(square(B))