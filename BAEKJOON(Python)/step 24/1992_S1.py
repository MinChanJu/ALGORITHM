import sys
input=sys.stdin.readline
def quadtree(A):
    n=len(A)
    s=0
    for i in range(n):
        for j in range(n):
            if i==0 and j==0:
                k=A[0][0]
            elif A[i][j]!=k:
                s=1
    if s==0:
        if k=='1':
            return "1"
        else:
            return "0"
    elif s==1:
        a=[[A[j][i] for i in range(n//2)] for j in range(n//2)]
        b=[[A[j][i] for i in range(n//2,n)] for j in range(n//2)]
        c=[[A[j][i] for i in range(n//2)] for j in range(n//2,n)]
        d=[[A[j][i] for i in range(n//2,n)] for j in range(n//2,n)]
        return "("+quadtree(a)+quadtree(b)+quadtree(c)+quadtree(d)+")"
N=int(input())
color_paper=[]
for i in range(N):
    color_paper.append(list(input().strip()))
for i in quadtree(color_paper):
    print(i,end='')