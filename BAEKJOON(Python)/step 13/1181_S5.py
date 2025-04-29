n=int(input())
ls=[]
for i in range(0,n):
    a=input()
    ls.append(a)
ls=list(set(ls))
ls.sort()
ls.sort(key=len)
for i in range(0,len(ls)):
    print(ls[i])