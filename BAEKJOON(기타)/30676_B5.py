import sys
input = sys.stdin.readline

answer = []

x = int(input())
if (620 <= x): print("Red")
elif (590 <= x): print("Orange")
elif (570 <= x): print("Yellow")
elif (495 <= x): print("Green")
elif (450 <= x): print("Blue")
elif (425 <= x): print("Indigo")
else: print("Violet")