from collections import deque
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    A, B = map(int,input().split())
    visit = [0]*10000
    queue = deque()
    queue.append([A,""])
    visit[A] = 1
    while queue:
        node,result = queue.popleft()
        if node == B:
            print(result)
            break
        D = (2*node)%10000
        S = (node-1)%10000
        L = (node%1000)*10 + node//1000
        R = (node%10)*1000 + node//10
        if visit[D] == 0:
            queue.append([D,result+"D"])
            visit[D] = 1
        if visit[S] == 0:
            queue.append([S,result+"S"])
            visit[S] = 1
        if visit[L] == 0:
            queue.append([L,result+"L"])
            visit[L] = 1
        if visit[R] == 0:
            queue.append([R,result+"R"])
            visit[R] = 1