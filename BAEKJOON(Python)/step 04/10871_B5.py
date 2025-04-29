N,X=map(int,input().split())
ls= input().split()
lk=[]
sum = 0
for i in range(0,N):
    if int(ls[i])<X:
        lk.append(ls[i])
        sum+=1
for j in range(0,sum):
    print(lk[j],end=' ')