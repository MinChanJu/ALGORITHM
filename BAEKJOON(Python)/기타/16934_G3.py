import sys
input = sys.stdin.readline

answers = []
N = int(input())
users = set()
user_count = {}
answers = []
for _ in range(N):
    user = input().strip()
    prefixIdx = 1
    while user[:prefixIdx] in users:
        prefixIdx += 1
        if prefixIdx > len(user): break
    
    nickname = user[:prefixIdx]
    if prefixIdx > len(user) and user in user_count:
        x = user_count[user]
        nickname += str(x + 1)
    if user not in user_count: user_count[user] = 1
    else: user_count[user] += 1
    
    for j in range(prefixIdx, len(user) + 1):
        users.add(user[:j])
    answers.append(nickname)

print(*answers, sep="\n")
