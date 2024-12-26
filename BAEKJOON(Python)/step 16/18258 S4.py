import sys
input=sys.stdin.readline
from collections import deque
n=int(input())
ls=deque()
for i in range(n):
    a=list(input().split())
    if a[0]=='push':
        ls.append(int(a[1]))
    elif a[0]=='pop':
        if ls:
            print(ls.popleft())
        else:
            print(-1)
    elif a[0]=='size':
        print(len(ls))
    elif a[0]=='empty':
        if ls:
            print(0)
        else:
            print(1)
    elif a[0]=='front':
        if ls:
            print(ls[0])
        else:
            print(-1)
    elif a[0]=='back':
        if ls:
            print(ls[-1])
        else:
            print(-1)