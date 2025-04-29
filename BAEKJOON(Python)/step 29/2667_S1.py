import sys
input = sys.stdin.readline

N = int(input())
graph = {(i//N,i%N):[] for i in range(N*N)}
visit = [0 for _ in range(N*N)]
result=[]
ls=[]
for _ in range(N):
    ls.append(list(map(int,list(input().rstrip()))))
for i in range(N*N):
    a=i//N
    b=i%N
    if a!=0 and ls[a-1][b]==1:
        graph[(a,b)].append((a-1,b))
    if b!=0 and ls[a][b-1]==1:
        graph[(a,b)].append((a,b-1))
    if a!=N-1 and ls[a+1][b]==1:
        graph[(a,b)].append((a+1,b))
    if b!=N-1 and ls[a][b+1]==1:
        graph[(a,b)].append((a,b+1))

def dfs(R):
    visit[R[0]*N+R[1]] = 1
    global count
    count += 1
    for x in graph[R]:
        if not visit[x[0]*N+x[1]]:
            dfs(x)
    return count

for i in range(N*N):
    count = 0
    if visit[i] == 0 and ls[i//N][i%N] == 1:
        result.append(dfs((i//N,i%N)))

print(len(result))
result.sort()
print(*result,sep='\n')