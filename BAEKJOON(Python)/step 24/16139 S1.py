import sys
input=sys.stdin.readline
S=list(input())
alpha={i:[0 for i in range(len(S))] for i in range(26)}
for i in range(len(S)-1):
    k=ord(S[i])-97
    for j in range(26):
        if k==j:
            alpha[j][i+1]=alpha[j][i]+1
        else:
            alpha[j][i+1]=alpha[j][i]
q=int(input())
for i in range(q):
    a,l,r =input().split()
    l,r=int(l),int(r)
    print(alpha[ord(a)-97][r+1]-alpha[ord(a)-97][l])