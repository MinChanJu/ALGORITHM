import sys
input=sys.stdin.readline

def canto(A,r):
    if r==0:
        return A
    for i in range(1,n//r,2):
        if A[i*r:(i+1)*r]!=' '*r:
            A[i*r:(i+1)*r]=' '*r
    return canto(A,r//3)

while 1:
    n=input().strip()
    if n.isdigit()==False:
        break
    n=3**int(n)
    A='-'*n
    for i in canto(list(A),n//3):
        print(i,end='')
    print('')