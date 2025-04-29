import sys
input = sys.stdin.readline

N, d, k, c = map(int, input().split())
sushi = [int(input()) for _ in range(N)]

cnt = []

for i in range(N-k+1):
  ls = set(sushi[i:i+k])
  if c in ls:
    cnt.append(len(ls))
  else:
    cnt.append(len(ls)+1)

for i in range(k-1):
  ls = set(sushi[:i+1]+sushi[N-k+i+1:])
  if c in ls:
    cnt.append(len(ls))
  else:
    cnt.append(len(ls)+1)

print(max(cnt))