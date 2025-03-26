import sys
input = sys.stdin.readline

find = ['a', 'e', 'i', 'o', 'u']
N = int(input())
S = input().rstrip()

cnt = 0
for i in find:
  cnt += S.count(i)

print(cnt)