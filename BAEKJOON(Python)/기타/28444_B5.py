import sys
input = sys.stdin.readline

H, I, A, R, C = map(int, input().split())
print((H*I)-(A*R*C))