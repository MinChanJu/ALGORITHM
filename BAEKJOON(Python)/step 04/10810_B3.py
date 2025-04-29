N,A=map(int,input().split(' '))
ls=[]
for var in range(0,N):
    ls.append(0)
for var in range(0,A):
    i,j,k=map(int,input().split())
    for vv in range(i-1,j):
        ls[vv]=k
for var in range(0,N):
    print(ls[var],end=' ')