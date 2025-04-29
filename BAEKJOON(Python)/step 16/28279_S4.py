import sys
input=sys.stdin.readline
from collections import deque
n=int(input())
ls=deque()
for _ in range(n):
    a=input().split()
    if a[0]=='1':
        ls.insert(0,int(a[1]))
    elif a[0]=='2':
        ls.append(int(a[1]))
    elif a[0]=='3':
        if ls:
            print(ls.popleft())
        else:
            print(-1)
    elif a[0]=='4':
        if ls:
            print(ls.pop())
        else:
            print(-1)
    elif a[0]=='5':
        print(len(ls))
    elif a[0]=='6':
        if ls:
            print(0)
        else:
            print(1)
    elif a[0]=='7':
        if ls:
            print(ls[0])
        else:
            print(-1)
    elif a[0]=='8':
        if ls:
            print(ls[-1])
        else:
            print(-1)