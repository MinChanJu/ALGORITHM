N=int(input())
ls=list(map(int,input().split()))
m=max(ls)
sum=0
for i in range(0,N):
    ls[i]=(ls[i]/m)*100
for i in range(0,N):
    sum+=ls[i]
print(sum/N)