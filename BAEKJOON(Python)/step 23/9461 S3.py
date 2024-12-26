import sys
input=sys.stdin.readline
lp=[1,1,1,2,2]
k=int(input())
for j in range(k):
    n=int(input())
    lp=[1,1,1,2,2]
    for i in range(5,n):
        lp.append(lp[i-5]+lp[i-1])
    print(lp[n-1])