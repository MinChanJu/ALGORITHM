import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int,input().split()))

count = [0 for i in range(1000001)]

for i in A:
    count[i]+=1

stack=[0]

for i in range(1,N):
    if count[A[i]]<=count[A[stack[-1]]]:
        stack.append(i)
    else:
        while len(stack)>0 and count[A[i]]>count[A[stack[-1]]]:
            A[stack.pop()]=A[i]
        stack.append(i)
for i in stack:
    A[i]=-1
A[-1]=-1
print(*A,sep=' ')