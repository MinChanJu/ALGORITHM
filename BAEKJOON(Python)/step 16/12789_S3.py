from collections import deque
n=int(input())
gan=deque(map(int,input().split()))
s=deque()
i=1
while gan:
    if gan and gan[0]==i:
        gan.popleft()
        i+=1
    else:
        s.append(gan.popleft())
    while s and s[-1]==i:
        s.pop()
        i+=1
if s:
    print("Sad")
else:
    print("Nice")