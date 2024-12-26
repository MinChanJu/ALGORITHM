n=int(input())
ls=[]
for i in range(0,n):
    ls.append(list(map(int,input().split())))
ls.sort(key=lambda x:(x[0],x[1]))
for i in ls:
    print(i[0],i[1])