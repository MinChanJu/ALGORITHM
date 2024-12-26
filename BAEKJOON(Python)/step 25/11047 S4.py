import sys
input=sys.stdin.readline
N,M=map(int,input().split())
ls=[]
for _ in range(N):
    ls.append(int(input()))
count=0
for i in range(N-1,-1,-1):
    count+=M//ls[i]
    M%=ls[i]
    if M==0:
        print(count)
        break