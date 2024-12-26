import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int,input().split()))
x = int(input())
A.sort()
count = 0
s = 0
e = n-1
while s<e:
    if A[s] + A[e] == x:
        count += 1
        s += 1
    elif A[s] + A[e] > x:
        e -= 1
    elif A[s] + A[e] < x:
        s += 1
print(count)