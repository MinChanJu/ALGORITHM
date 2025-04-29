import sys
input=sys.stdin.readline
n=int(input())
ls,d,k=[],{},[]
for _ in range(n):
    a=int(input())
    ls.append(a)
ls.sort()
for i in ls:
    if d.get(i)==None:
        d[i]=1
    else:
        d[i]+=1
s=list(d.values())
s.sort()
for i in d:
    if d[i]==s[-1]:
        k.append(i)
if len(k)==1:
    cen=k[0]
else:
    k.sort()
    cen=k[1]
print(round(sum(ls)/n))
print(ls[n//2])
print(cen)
print(max(ls)-min(ls))