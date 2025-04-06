from itertools import permutations
n=int(input())
ls=list(map(int,input().split()))
op=list(map(int,input().split()))
oper=[1]*op[0]+[2]*op[1]+[3]*op[2]+[4]*op[3]
lt=list(set(permutations(oper)))
def factorial(q):
    w=1
    for i in range(2,q+1):
        w*=i
    return w
t=factorial(n-1)//(factorial(op[0])*factorial(op[1])*factorial(op[2])*factorial(op[3]))
lp=[]
for r in range(t):
    s=ls[0]
    oper=list(lt[r])
    for i in range(n-1):
        if oper[i]==1:
            s+=ls[i+1]
        elif oper[i]==2:
            s-=ls[i+1]
        elif oper[i]==3:
            s=s*ls[i+1]
        elif oper[i]==4:
            if s<0:
                s=abs(s)//ls[i+1]
                s=-s
            elif s>=0:
                s=s//ls[i+1]
    lp.append(s)
print(max(lp))
print(min(lp))