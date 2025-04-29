import sys
n=int(sys.stdin.readline().strip())
ls,lk={},[]
a=list(map(int,sys.stdin.readline().split()))
for i in range(n):
    if a[i] in ls:
        ls[a[i]]+=1
    else:
        ls[a[i]]=1
m=int(sys.stdin.readline().strip())
lk=list(map(int,sys.stdin.readline().split()))
for i in lk:
    if i in ls:
        print(ls[i],end=' ')
    else:
        print(0,end=' ')