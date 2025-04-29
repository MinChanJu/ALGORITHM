from collections import deque
n=int(input())
ls=deque(enumerate(map(int,input().split()),start=1))
for _ in range(n):
    k=ls.popleft()
    print(k[0],end=' ')
    if k[1]>0:
        ls.rotate(-k[1]+1)
    else:
        ls.rotate(-k[1])