import sys
input=sys.stdin.readline
N,B=map(int,input().split())
A=[]
for _ in range(N):
    A.append(list(map(int,input().split())))

def mul(A,B):
    C=[]
    for i in range(len(A)):
        ls=[]
        for j in range(len(B)):
            sum=0
            for k in range(len(B[0])):
                sum+=A[i][k]*B[k][j]%1000
            ls.append(sum)
        C.append(ls)
    return C

def square(A,B):
    if B==1:
        return A
    else:
        C=square(A,B//2)
        if B%2==0:
            return mul(C,C)
        else:
            return mul(mul(C,C),A)
mat=square(A,B)
for i in range(N):
    for j in range(N):
        print(mat[i][j]%1000,end=' ')
    print('')