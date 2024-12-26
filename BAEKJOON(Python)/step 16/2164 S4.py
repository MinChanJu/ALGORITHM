from collections import deque
import sys
input = sys.stdin.readline

N = int(input())

card = deque(list(range(1,N+1)))

for i in range(2*N-3):
    x = card.popleft()
    if i%2 == 1: card.append(x)

print(card[0])