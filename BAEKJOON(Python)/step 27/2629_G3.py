import sys
input=sys.stdin.readline

N=int(input())
weight=list(map(int,input().split()))
M=int(input())
marble=list(map(int,input().split()))

possible = {}
for i in weight:
    ls=[]
    for j in possible.keys():
        ls.append(j+i)
        ls.append(i-j)
    for j in ls:
        possible[j]=True
    possible[i]=True

for i in marble:
    if possible.get(i):
        print("Y", end=' ')
    else:
        print("N", end=' ')