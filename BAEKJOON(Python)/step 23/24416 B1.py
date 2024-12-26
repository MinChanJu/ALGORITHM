def fib(n):
    global k
    k+=1
    if n == 1 or n == 2:
        k-=1
        return 1
    else:
        return (fib(n - 1) + fib(n - 2))
def fibonacci(n):
    global t
    f=[0,1,1]
    for i in range(3,n+1):
        t+=1
        f.append(f[i - 1] + f[i - 2])
    return f[n]
n=int(input())
k,t=0,0
fib(n)
fibonacci(n)
print(k+1,t)