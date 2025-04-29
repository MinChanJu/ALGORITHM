n=int(input())
for _ in range(n):
    a=list(input())
    for i in range(len(a)):
        for j in range(i,len(a)):
            if a[i]=='(' and a[j]==')':
                a[i],a[j]=0,0
    if a.count("(")==0 and a.count(")")==0:
        print("YES")
    else:
        print("NO")