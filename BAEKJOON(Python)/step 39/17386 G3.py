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

if ccw(p1,p2,p3)*ccw(p1,p2,p4) < 0 and ccw(p3,p4,p1)*ccw(p3,p4,p2) < 0: print(1)
else: print(0)