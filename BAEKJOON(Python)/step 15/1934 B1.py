import sys
import math
n=int(input())
for j in range(n):
    a,b=map(int,sys.stdin.readline().split())
    print(math.lcm(a,b))