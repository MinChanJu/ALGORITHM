N,A=map(int,input().split())
ls=[]
for i in range(0,N):
    ls.append(i+1)
for i in range(0,A):
    j,k=map(int,input().split())
    if k-j==1:
        ls[j-1],ls[k-1]=ls[k-1],ls[j-1]
        continue
    for s in range(j,(j+k)//2+1):
        ls[s-1],ls[k+j-s-1]=ls[k+j-s-1],ls[s-1]
for i in range(0,N):
    print(ls[i],end=' ')