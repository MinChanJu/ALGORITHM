import sys
input=sys.stdin.readline
def quadtree(A):
    global m1,p0,p1
    n=len(A)
    s=0
    for i in range(n):
        for j in range(n):
            if i==0 and j==0:
                k=A[0][0]
            elif A[i][j]!=k:
                s=1
    if s==0:
        if k==-1:
            m1+=1
        elif k==0:
            p0+=1
        else:
            p1+=1
    elif s==1:
        a=[[A[j][i] for i in range(n//3)] for j in range(n//3)]
        b=[[A[j][i] for i in range(n//3,n//3*2)] for j in range(n//3)]
        c=[[A[j][i] for i in range(n//3*2,n)] for j in range(n//3)]
        d=[[A[j][i] for i in range(n//3)] for j in range(n//3,n//3*2)]
        e=[[A[j][i] for i in range(n//3,n//3*2)] for j in range(n//3,n//3*2)]
        f=[[A[j][i] for i in range(n//3*2,n)] for j in range(n//3,n//3*2)]
        g=[[A[j][i] for i in range(n//3)] for j in range(n//3*2,n)]
        h=[[A[j][i] for i in range(n//3,n//3*2)] for j in range(n//3*2,n)]
        i=[[A[j][i] for i in range(n//3*2,n)] for j in range(n//3*2,n)]
        quadtree(a)
        quadtree(b)
        quadtree(c)
        quadtree(d)
        quadtree(e)
        quadtree(f)
        quadtree(g)
        quadtree(h)
        quadtree(i)
N=int(input())
color_paper=[]
for i in range(N):
    color_paper.append(list(map(int,input().split())))
m1,p0,p1=0,0,0
quadtree(color_paper)
print(m1)
print(p0)
print(p1)