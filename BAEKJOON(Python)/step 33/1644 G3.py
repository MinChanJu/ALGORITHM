import sys
input = sys.stdin.readline

N = int(input())

ls = [1]*(N+1)
prime =[]
for i in range(2,N+1):
    if ls[i] == 1:
        prime.append(i)
        for j in range(2*i,N+1,i):
            ls[j]=0
m = len(prime)
if m==0:
    e,count=111,0
else:
    s,e,SUM,count = 0,0,prime[0],0
while e < m:
    if SUM == N:
        count += 1
        SUM -= prime[s]
        s += 1
    elif SUM > N:
        SUM -= prime[s]
        s += 1
    else:
        e += 1
        if e < m:
            SUM += prime[e]
print(count)