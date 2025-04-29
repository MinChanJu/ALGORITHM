import sys
input=sys.stdin.readline
n=int(input())
ls=list(map(int,input().split()))
su,ma=0,-1000
for i in ls:
    su+=i
    if ma<su:
        ma=su
    if su<0:
        su=0
print(ma)