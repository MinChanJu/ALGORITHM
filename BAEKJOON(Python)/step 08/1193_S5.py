X=int(input())
i=1
while X>0:
    X=X-i
    i+=1
if i%2==0:
    print("%d/%d"%(1-X,i+X-1))
else:
    print("%d/%d"%(i+X-1,1-X))