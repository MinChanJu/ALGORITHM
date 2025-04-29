n=int(input())
age=[]
for i in range(0,n):
    a=input().split()
    a[0] = int(a[0])
    age.append(a)
age.sort(key=lambda x: x[0])
for i in range(0,n):
    print(age[i][0],age[i][1])