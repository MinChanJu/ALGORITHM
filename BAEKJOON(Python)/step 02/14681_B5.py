A=int(input())
B=int(input())
if A<0:
    if B<0:
        print("3")
    elif B>0:
        print("2")
elif A>0:
    if B<0:
        print("4")
    elif B>0:
        print("1")