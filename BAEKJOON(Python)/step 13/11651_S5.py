import sys
n=int(input())
ls=[]
for i in range(0,n):
    ls.append(list(map(int,sys.stdin.readline().split())))
ls.sort(key=lambda x:(x[1],x[0]))
for i in ls:
    print(i[0],i[1])