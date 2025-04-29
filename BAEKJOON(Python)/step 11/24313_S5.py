a,b=map(int,input().split())
c=int(input())
n=int(input())
if c*n>=a*n+b:
    if c>=a:
        print(1)
    else:
        print(0)
else:
    print(0)