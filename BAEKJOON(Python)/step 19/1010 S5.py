import sys
input = sys.stdin.readline
k =int(input())
for i in range(k):
    r,n=map(int,input().split())
    s,d,h=1,1,1
    for j in range(2,n+1):
    	s*=j
    for j in range(2,r+1):
        d*=j
    for j in range(2,n-r+1):
        h*=j
    print(s//(d*h))