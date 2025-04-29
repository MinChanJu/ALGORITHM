n=int(input())
for i in range(0,2*n-1):
    q='*'*(2*i+1)
    k=n-i-1
    if i>=n:
        q='*'*(4*n-3-2*i)
        k=i-n+1
    print(' '*k+q,)