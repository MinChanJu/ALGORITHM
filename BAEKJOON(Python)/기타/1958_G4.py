import sys
input = sys.stdin.readline

A = input().strip()
B = input().strip()
C = input().strip()

numA, numB, numC = len(A), len(B), len(C)
prev = [[0] * (numC + 1) for _ in range(numB + 1)]
curr = [[0] * (numC + 1) for _ in range(numB + 1)]
for i in range(1, numA + 1):
    for j in range(1, numB + 1):
        for k in range(1, numC + 1):
            if A[i - 1] == B[j - 1] == C[k - 1]:
                curr[j][k] = prev[j - 1][k - 1] + 1
            else:
                curr[j][k] = max([prev[j][k], curr[j - 1][k], curr[j][k - 1]])
    prev, curr = curr, prev

print(prev[numB][numC])
