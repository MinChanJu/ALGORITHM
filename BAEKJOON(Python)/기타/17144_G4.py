import sys
input = sys.stdin.readline

R, C, T = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(R)]

def spread(room):
    fine_dusts = []
    for r in range(R):
        for c in range(C):
            if room[r][c] <= 0: continue
            fine_dusts.append((r, c, room[r][c]))
            room[r][c] = 0
    
    for r, c, amount in fine_dusts:
        spread_amount = amount // 5
        cnt = 0
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nr, nc = r + dx, c + dy
            if nr < 0 or nr >= R: continue
            if nc < 0 or nc >= C: continue
            if room[nr][nc] == -1: continue
            
            room[nr][nc] += spread_amount
            cnt += 1
        
        room[r][c] += amount - (spread_amount * cnt)

def rotation(room):
    air_cleaner = [r for r in range(R) if room[r][0] == -1]
    
    up_r, up_c, up_amount = air_cleaner[0], 1, 0
    while up_r != air_cleaner[0] or up_c !=  0:
        room[up_r][up_c], up_amount = up_amount, room[up_r][up_c]
        if up_r == air_cleaner[0] and up_c != C - 1: up_c += 1
        elif up_r != 0 and up_c == C - 1: up_r -= 1
        elif up_r == 0 and up_c != 0: up_c -= 1
        elif up_r != air_cleaner[0] and up_c == 0 : up_r += 1
    
    down_r, down_c, down_amount = air_cleaner[1], 1, 0
    while down_r != air_cleaner[1] or down_c !=  0:
        room[down_r][down_c], down_amount = down_amount, room[down_r][down_c]
        if down_r == air_cleaner[1] and down_c != C - 1: down_c += 1
        elif down_r != R - 1 and down_c == C - 1: down_r += 1
        elif down_r == R - 1 and down_c != 0: down_c -= 1
        elif down_r != air_cleaner[1] and down_c == 0 : down_r -= 1

for _ in range(T):
    spread(room)
    rotation(room)

amount = 0
for r in range(R):
    for c in range(C):
        if room[r][c] <= 0: continue
        amount += room[r][c]

print(amount)
