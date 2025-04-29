n,k=map(int,input().split())
ls=list(map(int,input().split()))
ls.sort(reverse=True)
print(ls[k-1])