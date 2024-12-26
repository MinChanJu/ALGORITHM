import sys
input = sys.stdin.readline

T = input().rstrip()
P = input().rstrip()
n, m = len(T), len(P)
K = [0] * m

j = 0
for i in range(1, m):
    while j > 0 and P[i] != P[j]:
        j = K[j-1]

    if P[i] == P[j]:
        j += 1
        K[i] = j

j = 0
cnt = 0
result = []
for i in range(n):
    while j > 0 and T[i] != P[j]:
        j = K[j - 1]

    if T[i] == P[j]:
        if (j == m - 1):
            result.append(i - m + 2)
            cnt += 1
            j = K[j]
        else :
            j += 1

print(cnt)
print(*result)