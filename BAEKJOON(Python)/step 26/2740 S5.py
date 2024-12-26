import sys
input=sys.stdin.readline
N,M=map(int,input().split())
A=[]
for _ in range(N):
    A.append(list(map(int,input().split())))
M,K=map(int,input().split())
B=[]
for _ in range(M):
    B.append(list(map(int,input().split())))
C=[]
for i in range(N):
    ls=[]
    for j in range(K):
        sum=0
        for k in range(M):
            sum+=A[i][k]*B[k][j]
        ls.append(sum)
    C.append(ls)
for i in range(N):
    for j in range(K):
        print(C[i][j],end=' ')
    print('')