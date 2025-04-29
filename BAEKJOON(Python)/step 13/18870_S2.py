import sys
n=int(input())
ls=list(map(int,sys.stdin.readline().split()))
lk=list(set(ls[0:]))
lk.sort()
dic={lk[i]:i for i in range(len(lk))}
for i in ls:
    print(dic[i],end=' ')