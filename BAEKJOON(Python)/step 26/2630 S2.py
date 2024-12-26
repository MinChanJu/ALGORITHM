import sys
input=sys.stdin.readline
def quadtree(A):
    global blue,white
    n=len(A)
    s=0
    for i in range(n):
        for j in range(n):
            if i==0 and j==0:
                k=A[0][0]
            elif A[i][j]!=k:
                s=1
    if s==0:
        if k==1:
            blue+=1
        else:
            white+=1
    elif s==1:
        a=[[A[j][i] for i in range(n//2)] for j in range(n//2)]
        b=[[A[j][i] for i in range(n//2,n)] for j in range(n//2)]
        c=[[A[j][i] for i in range(n//2)] for j in range(n//2,n)]
        d=[[A[j][i] for i in range(n//2,n)] for j in range(n//2,n)]
        quadtree(a)
        quadtree(b)
        quadtree(c)
        quadtree(d)
N=int(input())
color_paper=[]
for i in range(N):
    color_paper.append(list(map(int,input().split())))
blue,white=0,0
quadtree(color_paper)
print(white)
print(blue)