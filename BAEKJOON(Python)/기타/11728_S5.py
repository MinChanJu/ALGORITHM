import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ls = []
ai, bi = 0, 0
while (ai < N and bi < M):
  if (A[ai] < B[bi]):
    ls.append(A[ai])
    ai += 1
  else:
    ls.append(B[bi])
    bi += 1

while (ai < N):
  ls.append(A[ai])
  ai += 1

while (bi < M):
  ls.append(B[bi])
  bi += 1

print(*ls)