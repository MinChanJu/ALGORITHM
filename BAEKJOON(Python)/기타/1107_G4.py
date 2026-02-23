import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
breakdown = list(map(int, input().split())) if M != 0 else []
possible = [i for i in range(10) if i not in breakdown]

min_num = abs(N - 100)
for i in range(1_000_000):
    possible_num = True
    for num in str(i):
        if int(num) not in possible:
            possible_num = False
            break
    if possible_num: min_num = min(min_num, len(str(i)) + abs(N - i))

print(min_num)
