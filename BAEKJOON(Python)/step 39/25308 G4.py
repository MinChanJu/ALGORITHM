from itertools import permutations
import sys
input = sys.stdin.readline

def direct(p1,p2,p3):
    slope = (p2[1]-p1[1])/(p2[0]-p1[0])
    section = p1[1]-slope*p1[0]
    direction = p3[1]-slope*p3[0]-section
    if p1[0]<p2[0]:
        if direction > 0:
            return 1
        elif direction < 0:
            return -1
        else:
            return 0
    elif p1[0] > p2[0]:
        if direction > 0:
            return -1
        elif direction < 0:
            return 1
        else:
            return 0

def convex(edge):
    p1 = (0,edge[0])
    p2 = (((edge[1]**2)/2)**(1/2),((edge[1]**2)/2)**(1/2))
    p3 = (edge[2],0)
    p4 = (((edge[3]**2)/2)**(1/2),-(((edge[3]**2)/2)**(1/2)))
    p5 = (0,-edge[4])
    p6 = (-(((edge[5]**2)/2)**(1/2)),-(((edge[5]**2)/2)**(1/2)))
    p7 = (-edge[6],0)
    p8 = (-(((edge[7]**2)/2)**(1/2)),((edge[7]**2)/2)**(1/2))
    if direct(p1,p2,p3) == 1: return 0
    if direct(p2,p3,p4) == 1: return 0
    if direct(p3,p4,p5) == 1: return 0
    if direct(p4,p5,p6) == 1: return 0
    if direct(p5,p6,p7) == 1: return 0
    if direct(p6,p7,p8) == 1: return 0
    if direct(p7,p8,p1) == 1: return 0
    if direct(p8,p1,p2) == 1: return 0
    return 1

ability = list(map(int,input().split()))
cnt = 0
for edge in list(permutations(ability,8)):
    cnt += convex(edge)
print(cnt)
