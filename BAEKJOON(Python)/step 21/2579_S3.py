import sys
input=sys.stdin.readline

def dp(ls,N,memo):
    if N in memo:
        return memo[N]
    else:
        memo[N]=max(dp(ls,N-3,memo)+ls[N-1],dp(ls,N-2,memo))+ls[N]
            
    return memo[N]
        
N=int(input())
ls=[0]
for i in range(N):
    ls.append(int(input()))

if N == 1:
    print(ls[1])
else:
    memo={0:0,1:ls[1],2:ls[1]+ls[2]}
    print(dp(ls,N,memo))