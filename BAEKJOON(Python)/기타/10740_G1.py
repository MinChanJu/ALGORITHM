import sys
input = sys.stdin.readline

N = int(input())
prefix_sum = [[0, *map(int, input().split())] for _ in range(3)]
for i in range(3):
    for j in range(2, N + 1):
        prefix_sum[i][j] += prefix_sum[i][j - 1]

min_difficulty = 5 * N
for first, second, third in ((0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), (2, 1, 0)):
    prefix_first, prefix_second, prefix_third = prefix_sum[first], prefix_sum[second], prefix_sum[third]
    min_first_second, prefix_third_N = 5 * N, prefix_third[N]
    for i in range(1, N):
        min_difficulty = min(min_difficulty, min_first_second + prefix_second[i] - prefix_third[i] + prefix_third_N)
        min_first_second = min(min_first_second, prefix_first[i] - prefix_second[i])

print(min_difficulty)