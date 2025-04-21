from collections import deque
import sys
input = sys.stdin.readline

N = int(input())

ls = deque()
for i in range(N, 0, -1):
  if (i%2 == 0): ls.append(i)
  else: ls.appendleft(i)
  
print(*ls)