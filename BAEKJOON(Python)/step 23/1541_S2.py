import sys
input=sys.stdin.readline
ls=list(input().split('-'))
total=0
for i in ls:
    k,h,SUM=0,0,0
    for j in i:
        if j=='+':
            SUM+=int(i[h:k])
            h=k+1
        k+=1
    SUM+=int(i[h:])
    total-=SUM
k,h,SUM=0,0,0
for i in ls[0]:
    if i=='+':
        SUM+=int(ls[0][h:k])
        h=k+1
    k+=1
SUM+=int(ls[0][h:])
total+=2*SUM
print(total)