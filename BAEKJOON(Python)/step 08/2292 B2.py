n=int(input())
i=1
if n!=1:
    i-=1
while n>=2:
    n=n-6*i
    i+=1
print(i)