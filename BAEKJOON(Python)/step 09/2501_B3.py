N,K=map(int,input().split())
ls=[]
i=1
while 1:
    if N%i==0:
        ls.append(i)
    i+=1
    if len(ls)==K or i>N:
        break
    
if len(ls)<K:
    print("0")
else:
    print(ls[-1])