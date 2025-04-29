import sys
input=sys.stdin.readline
N=int(input())
A=list(map(int,input().split()))
M=int(input())
B=list(map(int,input().split()))
def bi(A,i):
    s=0
    e=N-1
    while s<=e:
        mid=(s+e)//2
        if i<A[mid]:
            e=mid-1
        elif i>A[mid]:
            s=mid+1
        else:
            return 1
    return 0
A.sort()
for i in B:
    print(bi(A,i))