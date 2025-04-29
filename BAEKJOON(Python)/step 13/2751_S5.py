import sys
N=int(input())
ls=[]
for i in range(0,N):
    ls.append(int(sys.stdin.readline()))
ls.sort()
for i in ls:
    print(i)