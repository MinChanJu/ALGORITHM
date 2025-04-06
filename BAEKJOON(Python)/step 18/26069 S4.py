import sys
input=sys.stdin.readline
n=int(input())
d={"ChongChong":1}
for _ in range(n):
    a,b=input().strip().split()
    if d.get(a)==1:
        if d.get(b)==None:
            d[b]=1
    elif d.get(b)==1:
        if d.get(a)==None:
            d[a]=1
print(len(d))