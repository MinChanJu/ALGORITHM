a,b,c=input().split(" ")
a,b,c=int(a),int(b),int(c)
if a==b and b==c:
    print(10000+1000*a)
elif a==b or b==c:
    print(1000+100*b)
elif c==a:
    print(1000+100*a)
else:
    if a>b:
        if a>c:
            print(100*a)
        elif a<c:
            print(100*c)
    elif a<b:
        if b>c:
            print(100*b)
        elif b<c:
            print(100*c)
                