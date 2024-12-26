ls1,ls2=[],[]
N,M=map(int,input().split())
for i in range(0,N):
    ls1.append(list(map(int,input().split())))
for i in range(0,N):
    ls2.append(list(map(int,input().split())))
for i in range(0,N):
    for j in range(0,M):
        print(ls1[i][j]+ls2[i][j],end=' ')
        if i==N:
            break
    print('')