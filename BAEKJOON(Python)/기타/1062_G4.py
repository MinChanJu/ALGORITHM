import sys
from itertools import combinations
input = sys.stdin.readline

N, K = map(int, input().split())
antarcticWords = [input().rstrip() for _ in range(N)]

if K < 5:
    print(0)
    sys.exit(0)

def word_to_bit(word):
    bit = 0
    for s in word:
        bit |= 1 << (ord(s) - ord("a"))
    return bit

necessary = "antic"
necessary_check = word_to_bit(necessary)

filtered_words = [word_to_bit(word) ^ necessary_check for word in antarcticWords]

max_readable = 0
for ls in combinations([i for i in range(26) if i not in [0, 2, 8, 13, 19]], K-5):
    check_bit = 0
    for i in ls:
        check_bit |= 1 << i
    
    cnt = 0
    for word_bit in filtered_words:
        if word_bit & ~check_bit == 0: cnt += 1
    
    max_readable = max(max_readable, cnt)

print(max_readable)
