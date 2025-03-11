import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    S = input().rstrip()
    n = len(S)
    print(f"#{_+1} ", end="")
    if S[:] == S[::-1]:
        if S[:n//2] == S[n//2-1::-1]:
            if S[n//2+1:] == S[:n//2:-1]:
                print("YES")
            else: print("NO")
        else: print("NO")
    else: print("NO")