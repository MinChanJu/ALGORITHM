M=int(input())
N=int(input())
ls=[]
for i in range(M,N+1):
    if i==1:
        continue
    for j in range(2,i+1):
        if i==2:
            ls.append(i)
            break
        if i%j==0:
            break
        elif j>i/2:
            ls.append(i)
            break
if len(ls)==0:
    print("-1")
else:
    sum=0
    for i in ls:
        sum+=i
    print(sum)
    print(ls[0])