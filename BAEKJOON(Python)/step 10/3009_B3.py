ls=[]
for i in range(0,3):
    ls.append(tuple(map(int,input().split())))
count=1
for i in range(0,3):
    count=0
    for j in range(0,3):
        if i==j:
            continue
        if ls[i][0]==ls[j][0]:
            count+=1
    if count==0:
        print(ls[i][0],end=' ')
for i in range(0,3):
    count=0
    for j in range(0,3):
        if i==j:
            continue
        if ls[i][1]==ls[j][1]:
            count+=1
    if count==0:
        print(ls[i][1],end=' ')