import sys
input=sys.stdin.readline
n = int(input())
ls = list(map(int, input().split()))
inc = [0 for i in range(n)]
dec = [0 for i in range(n)]
k = Max = 0
for i in range(n):
    k = i
    for j in range(i):
        if ((ls[j] < ls[i]) and (inc[k] < inc[j])):
            k = j
    inc[i] = inc[k] + 1
for i in range(n-1, -1, -1):
    k = i
    for j in range(n-1, i-1, -1):
        if ((ls[j] < ls[i]) and (dec[k] < dec[j])):
            k = j
    dec[i] = dec[k] + 1
for i in range(n):
    if (Max < inc[i] + dec[i] - 1):
        Max = inc[i] + dec[i] - 1
print(Max)