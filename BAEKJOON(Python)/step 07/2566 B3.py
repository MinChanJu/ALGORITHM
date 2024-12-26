ls1,ls2=[],[]
for i in range(0,9):
    ls1.append(list(map(int,input().split())))
    ls2.append(max(ls1[i]))
print(max(ls2))
print(ls2.index(max(ls2))+1,ls1[ls2.index(max(ls2))].index(max(ls2))+1)