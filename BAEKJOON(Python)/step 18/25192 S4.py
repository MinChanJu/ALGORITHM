import sys
input=sys.stdin.readline
n=int(input())
sum,d=0,{}
for _ in range(n):
    a=input().strip()
    if a=='ENTER':
        sum+=len(d)
        d={}
    elif d.get(a)==None:
        d[a]=1
sum+=len(d)
print(sum)