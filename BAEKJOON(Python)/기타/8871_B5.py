import sys
input = sys.stdin.readline

answer = []

n = int(input())
answer = [(n+1)*2, (n+1)*3]

print(*answer,sep=" ")