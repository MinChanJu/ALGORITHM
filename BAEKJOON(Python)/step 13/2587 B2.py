ls=[]
for i in range(0,5):
    ls.append(int(input()))
ls.sort()
sum=0
for i in ls:
    sum+=i
print(sum//5)
print(ls[2])