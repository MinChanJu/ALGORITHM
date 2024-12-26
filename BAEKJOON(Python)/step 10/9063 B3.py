n=int(input())
x,y=[],[]
for i in range(0,n):
    a,b=map(int,input().split())
    x.append(a)
    y.append(b)
square = (max(x)-min(x))*(max(y)-min(y))
print(square)