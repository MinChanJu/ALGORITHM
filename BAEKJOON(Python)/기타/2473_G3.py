import sys
input = sys.stdin.readline

N = int(input())
solutions = list(map(int, input().split()))
solutions.sort()

answer = (abs(solutions[0] + solutions[1] + solutions[2]), solutions[0], solutions[1], solutions[2])
for i in range(N - 2):
    s, e = i + 1, N - 1
    while s < e:
        value = (solutions[i] + solutions[s] + solutions[e], solutions[i], solutions[s], solutions[e])
        if abs(value[0]) < abs(answer[0]):
            answer = value
        
        if value[0] > 0: e -= 1
        elif value[0] < 0: s += 1
        else: break

print(*answer[1:])
