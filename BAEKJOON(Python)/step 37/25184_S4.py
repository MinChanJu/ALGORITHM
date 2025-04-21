import sys
input = sys.stdin.readline

N = int(input())

ls = []
for i in range(1, N//2+1):
  ls.append(i+N//2)
  ls.append(i)
if (N%2 == 1):
  ls.append(N)
print(*ls)