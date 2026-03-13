import sys
input = sys.stdin.readline

N, M = map(int, input().split())
direct_boss = [0] + list(map(int, input().split()))
answers = [0] * (N + 1)

for _ in range(M):
    staff, w = map(int, input().split())
    answers[staff] += w

for staff in range(2, N + 1):
    answers[staff] += answers[direct_boss[staff]]

print(*answers[1:])
