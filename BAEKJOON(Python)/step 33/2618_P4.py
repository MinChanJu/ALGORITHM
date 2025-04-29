import sys
input = sys.stdin.readline

def find(a,b):
  next = max(a,b)+1
  if next == W+2:
    return
  if not DP[next][b]:
    find(next,b)
  if not DP[a][next]:
    find(a,next)  
  tmp1,tmp2 = DP[next][b]+incident[a][next],DP[a][next]+incident[b][next]
  if tmp1<tmp2:
    DP[a][b],car[a][b] = tmp1,1
  else:
    DP[a][b],car[a][b] = tmp2,2

N = int(input())
W = int(input())

case = [[1,1],[N,N]]+[[*map(int,input().split())] for i in range(W)]
incident = [[0]*(W+2) for i in range(W+2)]
for i in range(W+1):
  for j in range(i+1,W+2):
    incident[i][j] = abs(case[i][0]-case[j][0])+abs(case[i][1]-case[j][1])

DP,car = [[0]*(W+2) for i in range(W+2)],[[0]*(W+2) for i in range(W+2)]
find(0,1)
print(DP[0][1])
a,b = 0,1
while max(a,b)<W+1:
  print(car[a][b])
  if car[a][b] == 1:
    a = max(a,b)+1
  else:
    b = max(a,b)+1