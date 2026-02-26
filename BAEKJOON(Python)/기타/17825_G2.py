import sys
input = sys.stdin.readline

dice = list(map(int, input().split()))
board = {}

for i in range(20):
    board[i] = ([i+1], 2*i)

board[5][0].append(21)
board[10][0].append(27)
board[15][0].append(24)

board[21] = ([22], 13)
board[22] = ([23], 16)
board[23] = ([29], 19)

board[24] = ([25], 28)
board[25] = ([26], 27)
board[26] = ([29], 26)

board[27] = ([28], 22)
board[28] = ([29], 24)
board[29] = ([30], 25)
board[30] = ([31], 30)
board[31] = ([20], 35)

board[20] = ([100], 40)
board[100] = ([100], 0)

max_score = 0

def back(curPos = [0, 0, 0, 0], step = 0, score = 0):
    global dice, max_score
    if step >= len(dice):
        if score > max_score:
            max_score = score
        return
    
    dice_number = dice[step]
    
    for i in range(4):
        iPos = curPos[i]
        if iPos == 100: continue
        
        next_pos = board[iPos][0][-1]
        for _ in range(dice_number - 1):
            next_pos = board[next_pos][0][0]
        
        check = True
        for j in range(4):
            if next_pos == 100: break
            jPos = curPos[j]
            if jPos == next_pos:
                check = False
                break
        
        if not check: continue
        
        curPos[i] = next_pos
        back(curPos, step + 1, score + board[next_pos][1])
        curPos[i] = iPos


back()

print(max_score)
