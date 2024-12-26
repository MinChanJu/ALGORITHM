import sys
input = sys.stdin.readline

L = int(input())
ads = input().rstrip()

def build_prefix_table(pattern):
    prefix_table = [0] * len(pattern)
    j = 0

    for i in range(1, len(pattern)):
        while j > 0 and pattern[i] != pattern[j]:
            j = prefix_table[j-1]
    
        if pattern[i] == pattern[j]:
            j += 1
            prefix_table[i] = j
    
    return prefix_table

prefix_table = build_prefix_table(ads)

print(L-prefix_table[-1])