import sys
input = sys.stdin.readline

L, K, C = map(int, input().split())
cut_points = list(map(int, input().split()))
cut_points.sort()

def check(mid):
    cnt = 0
    last = L
    for i in range(K - 2, -1, -1):
        if last - cut_points[i] <= mid: continue
        if cut_points[i + 1] >= last or last - cut_points[i + 1] > mid: return False, last
        
        last = cut_points[i + 1]
        cnt += 1

    if last - cut_points[0] > mid: return False, last
    if last > mid or cnt < C:
        last = cut_points[0]
        cnt += 1
    if last > mid: return False, last
    if cnt > C: return False, last
    
    return True, last

s, e = 0, L
while s <= e:
    mid = (s + e) // 2
    possible, last = check(mid)
    if possible:
        answer = f"{mid} {last}"
        e = mid - 1
    else: s = mid + 1

print(answer)
