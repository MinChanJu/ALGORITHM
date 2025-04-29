import sys
input = sys.stdin.readline

answer = []

T = int(input())
for _ in range(T):
  n = int(input())
  cloth = {}
  for i in range(n):
    name, type = map(str, input().split())
    if (type in cloth): cloth[type].append(name)
    else: cloth[type] = [name]
  
  sum = 1
  for k in cloth:
    sum *= len(cloth[k])+1
  answer.append(sum-1)

print(*answer,sep="\n")