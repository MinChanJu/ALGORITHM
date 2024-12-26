def Hanoi_num(n,a,b,c):
    global k
    k+=1
    if n==1:
        return k
    else:
        Hanoi_num(n-1,a,c,b)
        Hanoi_num(n-1,b,a,c)

def Hanoi(n,a,b,c):
    global k
    k+=1
    if n==1:
        print(a,c)
    else:
        Hanoi(n-1,a,c,b)
        print(a,c)
        Hanoi(n-1,b,a,c)
n=int(input())
k=0
Hanoi_num(n,1,2,3)
print(k)
Hanoi(n,1,2,3)