a=list(map(int,input().split()))
k=max(a)
if k>=sum(a)-k:
    a[a.index(k)]=sum(a)-k-1
    print(sum(a))
else:
    print(sum(a))