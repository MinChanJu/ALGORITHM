import sys
input=sys.stdin.readline
ls=list(map(int,input().split()))
while ls[0]!=0:
    ls=ls[1:]+[0]
    lp=[]
    MAX=ls[1]
    for i in range(len(ls)):
        while lp and ls[lp[-1]]>ls[i]:
            t=lp.pop()
            s=i if not lp else i-lp[-1]-1
            MAX=max(MAX,ls[t]*s)
        lp.append(i)
    while lp:
        t=lp.pop()
        s=len(ls) if not lp else len(ls)-lp[-1]-1
        MAX=max(MAX,ls[t]*s)
    print(MAX)
    ls=list(map(int,input().split()))