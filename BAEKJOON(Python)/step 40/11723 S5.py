import sys
input=sys.stdin.readline
M=int(input())
S=set()
for _ in range(M):
    a=input().split()
    if a[0]=='all':
        S=set([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20])
    elif a[0]=='empty':
        S=set()
    elif a[0]=='add':
        if not int(a[1]) in S:
            S.add(int(a[1]))
    elif a[0]=='remove':
        if int(a[1]) in S:
            S.remove(int(a[1]))
    elif a[0]=='check':
        if int(a[1]) in S:
            print(1)
        else:
            print(0)
    elif a[0]=='toggle':
        if int(a[1]) in S:
            S.remove(int(a[1]))
        else:
            S.add(int(a[1]))