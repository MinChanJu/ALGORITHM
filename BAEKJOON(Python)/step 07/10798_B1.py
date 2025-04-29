ls=[]
for i in range(0,5):
    ls1=list(input())
    while len(ls1)<15:
        ls1.append('*')
    ls.append(ls1)
for i in range(0,15):
    for j in range(0,5):
        if ls[j][i] =='*':
            continue
        print(ls[j][i],end='')