N,M=map(int,input().split())
ls=[]
for k in range(0,N):
    ls.append(k+1)
for k in range(0,M):
    j,k=map(int,input().split())
    ls[j-1],ls[k-1]=ls[k-1],ls[j-1]
for k in range(0,N):
    print(ls[k],end=' ')