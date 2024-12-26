n=int(input())
ls=list(map(int,input().split()))
for i in range(0,n):
    if ls[i]==1:
        ls[i]=0
        continue
    for j in range(2,ls[i]):
        if ls[i]%j==0:
            ls[i]=0
            break
print(len(ls)-ls.count(0))