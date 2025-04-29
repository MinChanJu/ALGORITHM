import sys
input=sys.stdin.readline
a,b=map(int,input().split())
c,d=map(int,input().split())
i,j=b,d
x=b*d
while 1:
    if b>d:
        if b%d == 0:
            g=d
            break
        else:
            b=b%d
    else:
        if d%b == 0:
            g=b
            break
        else:
            d=d%b
l=x//g
a*=(l//i)
c*=(l//j)
m=a+c
k=l
while 1:
    if m>k:
        if m%k == 0:
            g=k
            break
        else:
            m=m%k
    else:
        if k%m == 0:
            g=m
            break
        else:
            k=k%m
print((a+c)//g,l//g)