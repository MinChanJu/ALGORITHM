a,b,c=map(int,input().split())
while a!=0:
    if max([a,b,c])>=a+b+c-max([a,b,c]):
        print("Invalid")
    else:
        if a==b==c:
            print("Equilateral")
        elif a==b or b==c or c==a:
            print("Isosceles")
        else:
            print("Scalene")
    a,b,c=map(int,input().split())