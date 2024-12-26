import sys
input = sys.stdin.readline

x1,y1,x2,y2 = map(int,input().split())
x3,y3,x4,y4 = map(int,input().split())
p1, p2, p3, p4 = [x1,y1], [x2, y2], [x3, y3], [x4, y4]

def ccw(p1,p2,p3):
    direction = p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p1[1] - (p2[0]*p1[1] + p3[0]*p2[1] + p1[0]*p3[1])
    if direction > 0: return 1
    elif direction < 0: return -1
    else: return 0

ccw1 = ccw(p1, p2, p3) * ccw(p1, p2, p4)
ccw2 = ccw(p3, p4, p1) * ccw(p3, p4, p2)

if not ccw1 and not ccw2:
    if min(x1, x2) <= max(x3, x4) and max(x1, x2) >= min(x3, x4) and min(y1, y2) <= max(y3, y4) and max(y1, y2) >= min(y3, y4): print(1) 
    else: print(0)
elif ccw1 <= 0 and ccw2 <= 0: print(1)
else: print(0)