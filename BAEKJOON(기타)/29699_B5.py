import sys
input = sys.stdin.readline

s = "WelcomeToSMUPC"
n = int(input())
print(s[(n-1)%len(s)])
