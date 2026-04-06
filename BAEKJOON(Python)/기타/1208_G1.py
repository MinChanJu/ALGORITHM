import sys
input = sys.stdin.readline

N, S = map(int, input().split())
sequence = list(map(int, input().split()))

def back(sequence, min_value = None, count_map = None, total_sum = 0, idx = 0):
    if count_map is None or min_value is None:
        min_value, max_value = 0, 0
        for value in sequence:
            if value > 0: max_value += value
            else: min_value += value
        count_map = [0] * (max_value - min_value + 1)
    
    if idx == len(sequence):
        count_map[total_sum - min_value] += 1
        return count_map, min_value
    
    back(sequence, min_value, count_map, total_sum + sequence[idx], idx + 1)
    back(sequence, min_value, count_map, total_sum, idx + 1)
    return count_map, min_value

left_count_map, left_min_value = back(sequence[:N // 2])
right_count_map, right_min_value = back(sequence[N // 2:])

cnt = 0
for i in range(len(left_count_map)):
    if left_count_map[i] == 0: continue
    x = i + left_min_value
    j = S - x - right_min_value
    if 0 <= j < len(right_count_map):
        if right_count_map[j] == 0: continue
        cnt += left_count_map[i] * right_count_map[j]
if S == 0: cnt -= 1

print(cnt)
