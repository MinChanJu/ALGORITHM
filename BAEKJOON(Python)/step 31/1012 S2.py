import sys
input = sys.stdin.readline

def dfs(R):
    stack=[R]
    while stack:
        node = stack.pop()
        if visit[node[0]*M+node[1]] == 0:
            visit[node[0]*M+node[1]] = 1
            for x in graph[node]:
                if not visit[x[0]*M+x[1]]:
                    stack.append(x) 
    return 1

T = int(input())
for _ in range(T):
    M, N, K = map(int,input().split())
    graph = {(i//M,i-i//M*M):[] for i in range(N*M)}
    visit = [0 for _ in range(N*M)]
    result=[]
    ls=[[0 for _ in range(M)] for _ in range(N)]
    for _ in range(K):
        x, y = map(int,input().split())
        ls[y][x]=1

    for i in range(N*M):
        a=i//M
        b=i-a*M
        if a!=0 and ls[a-1][b]==1:
            graph[(a,b)].append((a-1,b))
        if b!=0 and ls[a][b-1]==1:
            graph[(a,b)].append((a,b-1))
        if a!=N-1 and ls[a+1][b]==1:
            graph[(a,b)].append((a+1,b))
        if b!=M-1 and ls[a][b+1]==1:
            graph[(a,b)].append((a,b+1))
    
    for i in range(N*M):
        count = 0
        a=i//M
        b=i-a*M
        if visit[i] == 0 and ls[a][b] == 1:
            result.append(dfs((a,b)))
    print(len(result))