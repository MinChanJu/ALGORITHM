li = []
n = int(input())
for i in range(n):
    word = input()
    word_list = []
    for b in range(len(word)):
        word_list.append(word[b])
    forcount = []
    for a in range(len(word_list)):
        z = word_list[a]
        if z in forcount:
            if word_list[a-1] == z:
                forcount.append(z)
            else:
                pass
        else:
            forcount.append(z)
    if len(word_list) == len(forcount):
        li.append(word)
print(len(li))