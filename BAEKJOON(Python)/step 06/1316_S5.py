import sys
input = sys.stdin.readline

cnt = 0

n = int(input())
for _ in range(n):
    word = input().rstrip()
    count = [0]*26
    flag = True
    count[ord(word[0])-97] = 1
    for i in range(1, len(word)):
        z = word[i]
        if count[ord(z)-97] == 1:
            if word[i-1] != z:
                flag = False
                break
        else:
            count[ord(z)-97] = 1
    if (flag): cnt += 1

print(cnt)