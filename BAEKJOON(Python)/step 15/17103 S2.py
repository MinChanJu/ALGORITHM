import sys
input=sys.stdin.readline
ls=[1]*1000001
prime=[]
for i in range(2,1000000):
    if ls[i]:
        prime.append(i)
        for j in range(2*i,1000001,i):
            ls[j]=0
def gold(n):
    count=0
    for i in prime:
        if i>n//2:
            print(count)
            break
        elif ls[n-i]:
            count+=1
T=int(input())
for _ in range(T):
    gold(int(input()))