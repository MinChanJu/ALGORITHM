import sys
input=sys.stdin.readline
n=int(input())
ls=[]
for i in range(n):
    ls.append(list(map(int,input().split())))
for i in range(n-1):
    for j in range(i+1):
        if j==0:
            ls[i+1][j]+=ls[i][j]
            ls[i+1][j+1]+=ls[i][j]
            continue
        if ls[i][j]<ls[i][j-1]:
            ls[i+1][j+1]+=ls[i][j]
        elif ls[i][j]>=ls[i][j-1]:
            ls[i+1][j+1]+=ls[i][j]
            ls[i+1][j]+=ls[i][j]-ls[i][j-1]
print(max(ls[-1]))