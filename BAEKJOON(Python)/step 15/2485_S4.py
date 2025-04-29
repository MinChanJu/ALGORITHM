import sys
input=sys.stdin.readline
n=int(input())
ls,b=[],0
for i in range(n):
    a=int(input())
    b=a-b
    ls.append(b)
    b=a
    if i==0:
        mi=a
    elif i==n-1:
        ma=a
ls.remove(ls[0])
ls.sort()
a=ls[0]
for i in range(1,n-1):
    b=ls[i]
    while 1:
        if a>b:
            if a%b==0:
                a=b
                break
            a=a%b
        elif a<b:
            if b%a==0:
                break
            b=b%a
        elif a==b:
            break
print((ma-mi)//a-n+1)