import sys
input=sys.stdin.readline
N=int(input())
ls=[]
for i in range(N):
    a=list(map(int,input().split()))
    if a[0]==1:
        ls.append(a[1])
    elif a[0]==2:
        if len(ls)!=0:
            print(ls.pop())
        else:
            print(-1)
    elif a[0]==3:
        print(len(ls))
    elif a[0]==4:
        if len(ls)==0:
            print(1)
        else:
            print(0)
    elif a[0]==5:
        if len(ls)==0:
            print(-1)
        else:
            print(ls[-1])