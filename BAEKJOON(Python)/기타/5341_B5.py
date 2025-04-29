import sys
input = sys.stdin.readline

answer = []

while 1:
  n = int(input())
  if (n == 0): break
  answer.append(((n+1)*n)//2)

print(*answer,sep="\n")