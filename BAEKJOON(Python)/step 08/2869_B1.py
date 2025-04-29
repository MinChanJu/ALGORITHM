A,B,V=map(int,input().split())
k=(V-A)/(A-B)+1
if k%1==0:
    k=int(k)
    print(k)
else:
    k=int(k)
    print(k+1)