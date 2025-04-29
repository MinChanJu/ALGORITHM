a,b=map(int,input().split())
while 1:
    k=0
    if a>b:
        break
    if a<=1:
        a=2
    for i in range(2,int(a**(0.5))+1):
        if a%i==0:
            k=1
            break
    if k==0:
        print(a)
    a+=1