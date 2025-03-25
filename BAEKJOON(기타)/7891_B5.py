import sys
input = sys.stdin.readline

answer = []

T = int(input())
for _ in range(T):
  answer.append(sum(list(map(int, input().split()))))

print(*answer,sep="\n")