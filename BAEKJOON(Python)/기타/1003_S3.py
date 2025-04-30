import sys
input=sys.stdin.readline
def fibonacci(n):
    k=len(z)
    if n>=k:
        for i in range(k,n+1):
            z.append(z[i-1]+z[i-2])
            o.append(o[i-1]+o[i-2])
    print(z[n],o[n])

T=int(input())
for i in range(T):
    z=[1,0,1]
    o=[0,1,1]
    fibonacci(int(input()))