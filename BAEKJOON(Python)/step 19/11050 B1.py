n,r=map(int,input().split())
i,j,k=1,1,1
for s in range(2,n+1):
    i*=s
for s in range(2,r+1):
    j*=s
for s in range(2,n-r+1):
    k*=s
print(i//(j*k))