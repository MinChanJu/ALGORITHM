n=int(input())
lk={1:1,2:2}
for i in range(3,n+1):
    lk[i]=(lk[i-1]+lk[i-2])%15746
print(lk[n])