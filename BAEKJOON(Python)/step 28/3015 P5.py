import sys
input = sys.stdin.readline

N = int(input())
person=[]
for i in range(N):
    person.append(int(input()))

stack=[]
count=0
for i in person:
    while stack and stack[-1][0]<i:
        count += stack.pop()[1]
    if not stack:
        stack.append([i,1])
    elif stack[-1][0]==i:
        c = stack.pop()[1]
        count += c
        if stack:
            count+=1
        stack.append([i,c+1])
    else:
        stack.append([i,1])
        count+=1
print(count)