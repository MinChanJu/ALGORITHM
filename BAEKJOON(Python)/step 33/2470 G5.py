import sys
input = sys.stdin.readline

N = int(input())
feature = list(map(int,input().split()))
feature.sort()
s = 0
e = N-1
Min = [abs(feature[0]+feature[1]),feature[0],feature[1]]
while s<e:
    if abs(feature[s] + feature[e]) < Min[0]:
        Min = [abs(feature[s]+feature[e]),feature[s],feature[e]]
    if abs(feature[s+1] + feature[e]) < abs(feature[s] + feature[e-1]):
        s += 1
    else:
        e -= 1  
print(Min[1],Min[2])