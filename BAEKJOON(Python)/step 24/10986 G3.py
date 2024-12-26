import sys
input=sys.stdin.readline
N,M=map(int,input().split())
ls=list(map(int,input().split()))
dp,ld=[],[0]*M
dp.append(ls[0]%M)
for i in range(1,N):
    dp.append((dp[i-1]+ls[i])%M)
ld[0]+=1
for i in dp:
    ld[i]+=1
count=0
for i in ld:
    count+=i*(i-1)//2
print(count)