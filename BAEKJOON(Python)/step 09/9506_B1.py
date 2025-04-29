n=int(input())
while n!=-1:
    ls=[]
    for i in range(2,int(n**(1/2))+1):
        if n%i==0:
            ls.append(i)
            if i!=n//i:
                ls.append(n//i)
    ls.sort()
    sum=1
    for i in ls:
        sum+=i
    if sum==n:
        print(n,'= 1',end='')
        for i in ls:
            print(' +',i,end='')
        print('')
    else:
        print(n,"is NOT perfect.")
    n=int(input())