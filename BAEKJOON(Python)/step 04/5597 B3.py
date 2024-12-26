ls=[]
for i in range(0,30):
    ls.append(i+1)
for i in range(0,28):
    N = int(input())
    ls.remove(N)
print(ls[0])
print(ls[1])