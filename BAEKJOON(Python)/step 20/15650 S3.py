from itertools import permutations
N,M=map(int,input().split())
ls=[x for x in range(1,N+1)]
lk=list(permutations(ls,M))
for i in lk:
    k=0
    for j in range(0,M):
        for s in range(j+1,M):
            if i[j]>i[s]:
                k=1
    if k==0:
        for j in i:
            print(j,end=' ')
        print('')