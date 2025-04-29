n,m=map(int,input().split())
while n!=0:
    if n>m:
        if n%m==0:
            print("multiple")
        else:
            print("neither")
    if n<m:
        if m%n==0:
            print("factor")
        else:
            print("neither")
    n,m=map(int,input().split())