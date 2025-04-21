import sys
input = sys.stdin.readline

N = int(input())

ls = []
for i in range(1, N//2+1):
  ls.append(i)
  ls.append(N-i+1)
if (N%2 == 1):
  ls.append((N+1)//2)
print(*ls)