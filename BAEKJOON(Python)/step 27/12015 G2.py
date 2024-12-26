import sys
input=sys.stdin.readline
N=int(input())
A=list(map(int,input().split()))
LIS=[A[0]]
c=1
for i in range(1,N):
    if A[i]>LIS[-1]:
        LIS.append(A[i])
        c+=1
    elif A[i]<LIS[-1]:
        s=0
        e=c-1
        while s<=e:
            mid=(s+e)//2
            if LIS[mid]<A[i]:
                s=mid+1
            else:
                e=mid-1
        LIS[s]=A[i]
print(len(LIS))