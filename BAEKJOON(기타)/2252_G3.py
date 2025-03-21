import sys
input = sys.stdin.readline

def compare(a, b, ls):
  if (a in ls[b]): return -1
  if (b in ls[a]): return 1
  return 0

N, M = map(int, input().split())
students = list(range(1, N+1))

check = {i: [] for i in range(1, N+1)}
for i in range(M):
  a, b = map(int, input().split())
  check[a].append(b)

def mergeSort(ls, s, e):
  if (s >= e): return ls
  mid = (s+e) // 2
  ls = mergeSort(ls, s, mid)
  ls = mergeSort(ls, mid+1, e)
  
  new = []
  si, ei = s, mid+1
  while (si <= mid and ei <= e):
    idx = compare(ls[si], ls[ei], check)
    if (idx >= 0):
      new.append(ls[si])
      si += 1
    else:
      new.append(ls[ei])
      ei += 1
  
  while (si <= mid):
    new.append(ls[si])
    si += 1
  
  while (ei <= e):
    new.append(ls[ei])
    ei += 1
  
  for i in range(s, e+1):
    ls[i] = new[i-s]
  
  return ls

students = mergeSort(students, 0, N-1)
print(*students)