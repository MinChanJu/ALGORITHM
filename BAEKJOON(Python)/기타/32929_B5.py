import sys
input = sys.stdin.readline

answer = "UOS"

x = int(input())

print(answer[(x-1)%3])