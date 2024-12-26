n=int(input())
chess=[0]*n
k=0
def cross(t):
    for i in range(t):
        if chess[t]==chess[i] or abs(chess[t]-chess[i])==abs(t-i):
            return 0
    return 1
def dfs(t):
    global k
    if t==n:
        k+=1
        return
    else:
        for i in range(n):
            chess[t]=i
            if cross(t):
                dfs(t+1)
dfs(0)
print(k)