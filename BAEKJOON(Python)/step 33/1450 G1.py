from itertools import combinations
import sys
input = sys.stdin.readline

N, C = map(int, input().split())
object = list(map(int, input().split()))

left = object[:N//2]
right = object[N//2:]

left_sum = []
right_sum = []

for i in range(len(left)+1):
    combs = combinations(left, i)
    for comb in combs:
        left_sum.append(sum(comb))

for i in range(len(right)+1):
    combs = combinations(right, i)
    for comb in combs:
        right_sum.append(sum(comb))

right_sum.sort()
count = 0

for sum in left_sum:
    if sum > C:
        continue
    s = 0
    e = len(right_sum) - 1
    while s <= e:
        mid = (s + e) // 2
        if right_sum[mid] + sum > C:
            e = mid - 1
        else:
            s = mid + 1
    count += e + 1

print(count)