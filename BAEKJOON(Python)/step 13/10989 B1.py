import sys
N=int(input())
ls=[0]*10001
for i in range(N):
    ls[int(sys.stdin.readline())]+=1
for i in range(10001):
    if ls[i]:
        for j in range(ls[i]):
            print(i)