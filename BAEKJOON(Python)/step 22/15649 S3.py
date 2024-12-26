from itertools import permutations
N,M=map(int,input().split())
ls=[x for x in range(1,N+1)]
for i in permutations(ls,M):
    for j in i:
        print(j,end=' ')
    print('')