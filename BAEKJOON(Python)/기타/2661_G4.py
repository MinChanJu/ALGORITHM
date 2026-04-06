import sys
input = sys.stdin.readline

N = int(input())

def back(sequence = "1"):
    number_of_digits = len(sequence)
    for length in range(1, number_of_digits // 2 + 1):
        left = sequence[-length-length:-length]
        right = sequence[-length:]
        if left == right: return
    
    if number_of_digits == N:
        print(sequence)
        sys.exit()
    
    for i in ["1", "2", "3"]:
        back(sequence + i)

back()
