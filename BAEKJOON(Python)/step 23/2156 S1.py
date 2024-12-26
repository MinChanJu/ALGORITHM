import sys
input=sys.stdin.readline
n = int(input())
ls = [0] * (n+3)
Max = [0] * (n+3)
for i in range(3,n+3):
    ls[i] = int(input())
    Max[i] = max(Max[i-2] + ls[i], Max[i-3] + ls[i-1] + ls[i], Max[i-1])
print(max(Max))