from itertools import combinations_with_replacement
import sys
input = sys.stdin.readline

def solution(n):
  squares = [i*i for i in range(1, 224)]
  if (n in squares): return 1
  
  for a in squares:
    if a > n: break
    if (n - a) in squares: return 2
  
  for a in squares:
    if a > n: break
    for b in squares:
        if a + b > n: break
        if (n - a - b) in squares: return 3
  
  for a in squares:
    if a > n: break
    for b in squares:
        if a + b > n: break
        for c in squares:
            if a + b + c > n: break
            if (n - a - b - c) in squares: return 4
  
  return -1

n = int(input())
print(solution(n))