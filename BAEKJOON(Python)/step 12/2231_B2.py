N=int(input())
l=0
for i in range(1,N):
    sum=0
    k=list(map(int,str(i)))
    for j in k:
        sum+=j
    if sum+i==N:
        print(i)
        l+=1
        break
if l==0:
    print(0)