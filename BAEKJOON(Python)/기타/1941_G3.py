import sys
input = sys.stdin.readline

is_Y = [0] * 25
for i in range(5):
    line = input().strip()
    for j in range(5):
        if line[j] == 'Y':
            is_Y[i * 5 + j] = 1

adjacent = [0] * 25
for i in range(5):
    for j in range(5):
        idx = i * 5 + j
        for di, dj in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            ni, nj = i + di, j + dj
            if ni < 0 or ni >= 5: continue
            if nj < 0 or nj >= 5: continue
            adjacent[idx] |= 1 << (ni * 5 + nj)

def back(depth = 0, princesses = 0, y_cnt = 0):
    global answer
    if y_cnt >= 4: return
    if depth == 7:
        answer += 1
        return

    for idx in range(25):
        current = 1 << idx
        if current & princesses: continue
        if princesses and not adjacent[idx] & princesses: continue
        
        next_princesses = current | princesses
        if next_princesses in visited: continue
        visited.add(next_princesses)
        back(depth + 1, next_princesses, y_cnt + is_Y[idx])

visited = set()
answer = 0
back()
print(answer)
