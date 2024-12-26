import sys
input=sys.stdin.readline
N=int(input())
distance=list(map(int,input().split()))
oil_price=list(map(int,input().split()))
min_price=[]
j=0
for i in range(1,N):
    if oil_price[i] < oil_price[j]:
        min_price.append([oil_price[j],j,i])
        j=i
min_price.append([oil_price[j],j,N])
total_price=0
for i in min_price:
    total_price+=i[0]*sum(distance[i[1]:i[2]])
print(total_price)