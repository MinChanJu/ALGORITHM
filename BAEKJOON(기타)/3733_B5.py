import sys
input = sys.stdin.readline

answer = []

while (1):
  try:
    N, S = map(int, input().split())
    answer.append(S//(N+1))
  except:
    break
print(*answer,sep="\n")