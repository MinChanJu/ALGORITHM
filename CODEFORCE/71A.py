import sys
input = sys.stdin.readline

answer = []

T = int(input())
for _ in range(T):
    word = input().rstrip()
    l = len(word)
    if (l <= 10): answer.append(word)
    else: answer.append(word[0] + str(l-2) + word[-1])

print(*answer,sep="\n")