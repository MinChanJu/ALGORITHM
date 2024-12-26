import sys
input=sys.stdin.readline
lp={}
def w(a,b,c):
    if lp.get((a,b,c)):
        return lp[(a,b,c)]
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif a > 20 or b > 20 or c > 20:
        if lp.get((20,20,20)):
            return lp[(20,20,20)]
        lp[(20,20,20)]=lp[(a,b,c)]=w(20,20,20)
        return lp[(20,20,20)]
    elif a < b and b < c:
        if lp.get((a,b,c)):
            return lp[(a,b,c)]
        lp[(a,b,c)]=w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
        return lp[(a,b,c)]
    else:
        if lp.get((a,b,c)):
            return lp[(a,b,c)]
        lp[(a,b,c)]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return lp[(a,b,c)]

while 1:
    a,b,c=map(int,input().split())
    if a==-1 and b==-1 and c==-1:
        break
    else:
        print("w(%d, %d, %d) ="%(a,b,c),w(a,b,c))