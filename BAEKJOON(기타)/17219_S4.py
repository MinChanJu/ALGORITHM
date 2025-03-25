import sys
input = sys.stdin.readline

answer = []

N, M = map(int, input().split())
dic = {}
for _ in range(N):
  site, pw = input().split()
  dic[site] = pw
  
for _ in range(M):
  site = input().rstrip()
  answer.append(dic[site])

print(*answer,sep="\n")