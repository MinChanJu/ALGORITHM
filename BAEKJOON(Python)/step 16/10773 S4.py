import sys
input=sys.stdin.readline
n=int(input())
ls=[]
for i in range(n):
    a=int(input())
    if a==0:
        ls.pop()
    else:
        ls.append(a)
sum=0
for i in ls:
    sum+=i
print(sum)