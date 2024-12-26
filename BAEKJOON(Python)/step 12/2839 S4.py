N=int(input())
k=0
for i in range(N//5,-1,-1):
    for j in range(N//3+1):
        if 5*i+3*j==N:
            k=1
            print(i+j)
            break
            break
    if k==1:
        break
if k==0:
    print(-1)