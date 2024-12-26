n=int(input())
ls=[0,1,1,1,1,1,1,1,1,1]
for _ in range(1,n):
    ls[0],ls[1],ls[2],ls[3],ls[4],ls[5],ls[6],ls[7],ls[8],ls[9]=ls[1],ls[0]+ls[2],ls[1]+ls[3],ls[4]+ls[2],ls[3]+ls[5],ls[4]+ls[6],ls[5]+ls[7],ls[6]+ls[8],ls[7]+ls[9],ls[8]
print(sum(ls)%1000000000)