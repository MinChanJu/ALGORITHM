import sys
input=sys.stdin.readline

def solve(mid):
    count=0
    s=0
    e=mid
    lp=[]
    while s<=e:
        mid=(s+e)//2
        count=0
        f=ls[0]
        for i in range(N):
            if f>ls[-1]:
                break
            if ls[i]>=f:
                count+=1
                f=ls[i]+mid
        if count>=C:
            s=mid+1
            lp.append(mid)
        elif count<C:
            e=mid-1
    return max(lp)

N,C=map(int,input().split())
ls=[]
for _ in range(N):
    ls.append(int(input()))
ls.sort()
mid=(ls[0]+ls[-1])//(C-1)+1
print(solve(mid))