import sys
import heapq
input = sys.stdin.readline

def median(A, n):
  A.sort()
  return A[n//2]

T = int(input())

answer = []
for _ in range(T):
  M = int(input())
  num = []
  for i in range(((M-1)//10)):
    ls = list(map(int, input().split()))
    for i in ls:
      num.append(i)
  if (M%10 != 0):
    ls = list(map(int, input().split()))
    for i in ls:
      num.append(i)
  
  ls = []
  for i in range(1, M+1, 2):
    ls.append(str(median(num[:i], i)))
  
  answer.append((M+1)//2)
  for i in range(1, (M+1)//2//10+1):
    answer.append(' '.join(ls[(i-1)*10: i*10]))
  answer.append(' '.join(ls[(M+1)//2//10*10:]))

print(*answer, sep="\n")