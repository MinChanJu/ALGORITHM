from itertools import combinations
from itertools import permutations
import sys
input=sys.stdin.readline
n=int(input())
ls=[i for i in range(n)]
lp=list(combinations(ls,n//2))
lk=[]
for i in range(n):
    lk.append(list(map(int,input().split())))
t=2000
for x in range(len(lp)//2):
    s,q=0,0
    for a,b in list(permutations(lp[x],2)):
        s+=lk[a][b]
    for a,b in list(permutations(list(set(ls)-set(lp[x])),2)): 
        q+=lk[a][b]
    t=min(abs(s-q),t)
print(t)