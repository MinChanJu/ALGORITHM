import sys
input=sys.stdin.readline
n=2*123456
prime=[False]*n
for i in range(2,n):
    k=0
    for j in range(2,int(i**(0.5))+1):
        if i%j==0:
            k=1
            break
    if k==0:
        prime[i-1]=True
a=int(input())
while a!=0:
    print(prime[a:2*a].count(True))
    a=int(input())