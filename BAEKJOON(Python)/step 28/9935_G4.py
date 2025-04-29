import sys
input = sys.stdin.readline

sentence = list(input().rstrip())
explosion = list(input().rstrip())
stack = []

for i in range(len(sentence)):
    stack.append(sentence[i])
    while stack[-len(explosion):] == explosion:
        del stack[-len(explosion):]

if not stack:
    print("FRULA")
else:
    print(*stack,sep='')
