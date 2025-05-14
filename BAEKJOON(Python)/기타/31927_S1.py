import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = A[:]
ops = []
M = N // 2

for i in range(M):
  l, r = i, N - 1 - i
  LB, UB = 1, 10**6

  # 이전 왼쪽 유지
  if l > 0:
    UB = min(UB, A[l-1] - A[l])
  # 다음 왼쪽 유지
  if l+1 < N:
    LB = max(LB, A[l+1] - A[l])
  # 오른쪽 유지
  if r+1 < N:
    UB = min(UB, A[r] - A[r+1])

  if LB <= UB:
    x = UB
    A[l] += x
    A[r] -= x
    ops.append((l, r, x))

print(len(ops))
for l, r, x in ops:
  B[l] += x
  B[r] -= x
  print(*B)