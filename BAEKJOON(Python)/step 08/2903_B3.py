n=int(input())
dot=9
if n==1:
    print("9")
else:
    for i in range(2,n+1):
        dot+=5*(2**((2*i)-2))-((2**(i-1)-1)*(2**(i-1))*2)
    print(dot)