import sys
input = sys.stdin.readline

N, C = map(int, input().split())
nums = list(map(int, input().split()))

idx = 0
dic = {}
for num in nums:
  if (num in dic):
    dic[num][1] += 1
  else:
    dic[num] = [idx, 1]
    idx += 1

nums.sort(key=lambda x: (-dic[x][1], dic[x][0]))
print(*nums)