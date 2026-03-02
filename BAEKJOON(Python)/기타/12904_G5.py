import sys
input = sys.stdin.readline

S = input().rstrip()
T = input().rstrip()

while len(S) < len(T):
    sub = T[:len(T) - 1]
    if T[-1] == "A": T = sub
    else: T = sub[::-1]

if S == T: print(1)
else: print(0)
