import sys
input = sys.stdin.readline

answer = []

n = int(input())
s = int(input())
mid = (n-s)//2

print(mid+s, mid,sep="\n")