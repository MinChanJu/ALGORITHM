N=int(input())
max=N
sum=2
num=1
for i in range(0,8):
    N=int(input())
    if N>max:
        max=N
        num=sum
    sum+=1
print(max)
print(num)