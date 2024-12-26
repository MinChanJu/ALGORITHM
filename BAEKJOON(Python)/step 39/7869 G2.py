import math
import sys
input = sys.stdin.readline

x1, y1, r1, x2, y2, r2 = map(float,input().split())
d = ((x2-x1)**2 + (y2-y1)**2)**(1/2)

if d > r1+r2:
    ans = 0
elif d <= max(r1,r2) - min(r1,r2):
    ans = math.pi*(min(r1,r2)**2)
else:
    theta1 = 2*math.acos((r1**2 + d**2 - r2**2)/(2*r1*d))
    ans1 = r1*r1*(theta1 - math.sin(theta1))/2

    theta2 = 2*math.acos((r2**2 + d**2 - r1**2)/(2*r2*d))
    ans2 = r2*r2*(theta2 - math.sin(theta2))/2

    ans = ans1 + ans2
print(f"{round(ans,3):.3f}")