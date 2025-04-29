import  sys
input = sys.stdin.readline

N = int(input())
home = [[0,0,0]]
for _ in range(N):
    R, G, B = map(int,input().split())
    home.append([R,G,B])

def first(p):
    dp = [[0,0,0] for _ in range(N+1)]
    dp[1] = [float('inf'),float('inf'),float('inf')]
    dp[1][p] = home[1][p]
    
    for i in range(2, N+1):
        for j in range(3):
            if j == 0: a, b = 1, 2
            elif j == 1: a, b = 0, 2
            elif j == 2: a, b = 0, 1
            dp[i][j] = min(dp[i-1][a],dp[i-1][b]) + home[i][j]
        
    result = []
    for i in range(3):
        if i != p: result.append(dp[N][i])
        
    return result

answer = float('inf')
for i in range(3):
    ls = first(i)
    a,b = ls[0],ls[1]
    answer = min(answer,a,b)

print(answer)