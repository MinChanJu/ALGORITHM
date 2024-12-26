import sys
input=sys.stdin.readline
n=int(input())
for i in range(n):
    a=int(input())
    while 1:
        k=0
        if a<=1:
            print(2)
            break
        for i in range(2,int(a**(0.5))+1):
            if a%i==0:
                k=1
                break
        if k==0:
            print(a)
            break
        a+=1