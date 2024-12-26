T=int(input())
for i in range(0,T):
    A,N=input().split()
    A=int(A)
    for j in range(0,len(N)):
        print(N[j]*A,end='')
    print(" ")