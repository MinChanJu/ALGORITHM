import sys
input=sys.stdin.readline
n=int(input())
ls=[]
for _ in range(n):
    ls.append(list(map(int,input().split())))
for i in range(1,n):
    ls[i][0]+=min(ls[i-1][1],ls[i-1][2])
    ls[i][1]+=min(ls[i-1][0],ls[i-1][2])
    ls[i][2]+=min(ls[i-1][0],ls[i-1][1])
print(min(ls[-1]))