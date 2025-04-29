from itertools import product
N,M=map(int,input().split())
ls=[x for x in range(1,N+1)]
for i in product(ls,repeat=M):
    for j in i:
        print(j,end=' ')
    print('')