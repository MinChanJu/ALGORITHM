n,k=map(int,input().split())
ls,g=[],k-1
for i in range(n):
    ls.append(i+1)
print('<',end='')
while len(ls)!=0:
    if g<len(ls):
        print(ls[g],end='')
        ls.remove(ls[g])
        g+=k-1
    else:
        g-=len(ls)
        continue
    if len(ls)!=0:
        print(", ",end='')
print(">")