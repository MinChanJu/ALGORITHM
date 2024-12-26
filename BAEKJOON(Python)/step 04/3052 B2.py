ls=[]
lk=[]
for i in range(0,10):
    N=int(input())
    ls.append(N%42)
for i in range(0,10):
    if ls[i] in lk:
        continue
    else:
        lk.append(ls[i])
print(len(lk))