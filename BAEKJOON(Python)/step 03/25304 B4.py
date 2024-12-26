N=int(input())
A=int(input())
sum = 0
for i in range(0,A):
    b,c=input().split(' ')
    b,c=int(b),int(c)
    sum=b*c+sum
if N==sum:
    print("Yes")
else:
    print("No")