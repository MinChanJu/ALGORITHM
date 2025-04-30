from collections import deque
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, K = map(int,input().split())
    build = [0] + list(map(int,input().split()))
    seq=[[] for _ in range(N+1)]
    inDegree=[0 for _ in range(N+1)]
    DP=[0 for _ in range(N+1)]

    for _ in range(K):
        X, Y = map(int,input().split())
        seq[X].append(Y)
        inDegree[Y]+=1
    
    W = int(input())
    
    q = deque()
    for i in range(1,N+1):
        if inDegree[i]==0:
            q.append(i)
            DP[i]=build[i]

    while q:
        a=q.popleft()
        for i in seq[a]:
            inDegree[i]-=1
            DP[i]=max(DP[a]+build[i],DP[i])
            if inDegree[i]==0:
                q.append(i)

    print(DP[W])