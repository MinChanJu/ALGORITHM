import sys
input=sys.stdin.readline
ls = []
for _ in range(9):
    ls.append(list(map(int, input().split())))

lc = []
for i in range(9):
    col = []
    for j in range(9):
        col.append(ls[j][i])
    lc.append(col)

lt = []
for i in range(9):
    for j in range(9):
        if not ls[i][j]:
            lt.append([i, j])

def check_r(r, num):
    if num in ls[r]:
        return False
    return True

def check_c(c, num):
    if num in lc[c]:
        return False 
    return True

def check_s(r, c, num):
    r = r // 3 * 3
    c = c // 3 * 3
    for i in range(r, r+3):
        for j in range(c, c+3):
            if num == ls[i][j]:
                return False
    return True

def dfs(t):
    if t == len(lt):
        for row in ls:
            print(*row)
        exit(0)
    
    for i in range(1, 10):
        tr, tc = lt[t]
        if check_r(tr, i) and check_c(tc, i) and check_s(tr, tc, i):
            ls[tr][tc] = i
            lc[tc][tr] = i
            dfs(t+1)
            ls[tr][tc] = 0
            lc[tc][tr] = 0

dfs(0)