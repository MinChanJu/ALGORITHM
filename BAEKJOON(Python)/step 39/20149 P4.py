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

def get_cross(p1, p2, p3, p4):
    x1, y1 = p1
    x2, y2 = p2
    x3, y3 = p3
    x4, y4 = p4
    mx = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)
    my = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)
    m = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
    if not m:
        if p2 == p3 and p1 <= p3: return p2
        elif p1 == p4 and p3 <= p1: return p1
        return 0
    else:
        x = mx / m 
        y = my / m
        return x, y

ccw1 = ccw(p1, p2, p3) * ccw(p1, p2, p4)
ccw2 = ccw(p3, p4, p1) * ccw(p3, p4, p2)

if not ccw1 and not ccw2:
    if p1 > p2: p1, p2 = p2, p1
    if p3 > p4: p3, p4 = p4, p3
    if p1 <= p4 and p2 >= p3:
        print(1)
        p = get_cross(p1, p2, p3, p4)
        if p: print(p[0], p[1])
    else: print(0)
elif ccw1 <= 0 and ccw2 <= 0:
    print(1)
    p = get_cross(p1, p2, p3, p4)
    if p: print(p[0], p[1])
else: print(0)