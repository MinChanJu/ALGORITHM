import sys
input=sys.stdin.readline
n=int(input())
ls,lk=[],[]
for i in range(n):
    lk.append(list(map(int,input().split())))
lk.sort()
for i in lk:
    ls.append(i[1])
inc = [0 for i in range(n)]
k = 0
for i in range(n):
    k = i
    for j in range(i):
        if ((ls[j] < ls[i]) and (inc[k] < inc[j])):
            k = j
    inc[i] = inc[k] + 1
print(n-max(inc))