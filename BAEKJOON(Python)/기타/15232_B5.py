import sys
input = sys.stdin.readline


R = int(input())
C = int(input())

answer = ["*"*C]*R

print(*answer,sep="\n")