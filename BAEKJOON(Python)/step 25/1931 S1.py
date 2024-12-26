import sys
input=sys.stdin.readline
N=int(input())
ls,lk=[],[]
for _ in range(N):
    a=list(map(int,input().split()))
    ls.append(a)
ls.sort(key=lambda x : (x[0],x[1]-x[0]))
count=0
for i in ls:
    k=0
    if len(lk)==0:
        k=0
    elif i[1]<lk[-1][1]:
        lk.pop()
        count-=1
    elif i[0]<lk[-1][1]:
        k=1
    if k==0:
        lk.append(i)
        count+=1
print(count)