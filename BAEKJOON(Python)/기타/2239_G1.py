import sys
input = sys.stdin.readline

N = int(input())
slab = [list(map(int, input().split())) for _ in range(N)]

def solve(cut_slab, dir):
    clean = True
    gem = 0
    for i in range(len(cut_slab)):
        for j in range(len(cut_slab[0])):
            if cut_slab[i][j] == 1:
                clean = False
                break
            if cut_slab[i][j] == 2: gem += 1
        if not clean: break
    
    if clean and gem == 1: return 1
    if clean: return 0
    
    cnt = 0
    if dir == 0:
        for cut_i in range(len(cut_slab)):
            impurity_include = False
            gem_include = False
            for j in range(len(cut_slab[0])):
                if cut_slab[cut_i][j] == 1: impurity_include = True
                if cut_slab[cut_i][j] == 2: gem_include = True
            
            if not impurity_include or gem_include: continue
            
            good = 0
            if cut_i != 0:
                up_slab = [[cut_slab[i][j] for j in range(len(cut_slab[0]))] for i in range(cut_i)]
                res = solve(up_slab, (dir + 1) % 2)
                if res == 0: continue
                good = max(res, good)
            if cut_i + 1 != len(cut_slab):
                down_slab = [[cut_slab[i][j] for j in range(len(cut_slab[0]))] for i in range(cut_i + 1, len(cut_slab))]
                res = solve(down_slab, (dir + 1) % 2)
                if res == 0: continue
                good = max(res, good)
            cnt += good
    
    if dir == 1:
        for cut_j in range(len(cut_slab[0])):
            impurity_include = False
            gem_include = False
            for i in range(len(cut_slab)):
                if cut_slab[i][cut_j] == 1: impurity_include = True
                if cut_slab[i][cut_j] == 2: gem_include = True
            
            if not impurity_include or gem_include: continue
            
            good = 0
            if cut_j != 0:
                left_slab = [[cut_slab[i][j] for j in range(cut_j)] for i in range(len(cut_slab))]
                res = solve(left_slab, (dir + 1) % 2)
                if res == 0: continue
                good = max(res, good)
            if cut_j + 1 != len(cut_slab[0]):
                right_slab = [[cut_slab[i][j] for j in range(cut_j + 1, len(cut_slab[0]))] for i in range(len(cut_slab))]
                res = solve(right_slab, (dir + 1) % 2)
                if res == 0: continue
                good = max(res, good)
            cnt += good

    return cnt

res = solve(slab, 0) + solve(slab, 1)
print(res if res else -1)
