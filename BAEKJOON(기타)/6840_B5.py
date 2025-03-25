import sys
input = sys.stdin.readline

ls = [int(input()) for _ in range(3)]

print(sum(ls)-max(ls)-min(ls))