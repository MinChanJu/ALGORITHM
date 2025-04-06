import sys
input=sys.stdin.readline
N=int(input())
A=[[1,1],[1,0]]
def mul(A,B):
    C=[]
    for i in range(2):
        ls=[]
        for j in range(2):
            sum=0
            for k in range(2):
                sum+=A[i][k]*B[k][j]%1000000007
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
mat=square(A,N)
print(mat[0][1]%1000000007)