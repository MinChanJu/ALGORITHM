n=list(input())
ls=[]
for i in range(0,26):
    ls.append(n.count(chr(i+65))+n.count(chr(i+97)))
if ls.count(max(ls))==1:
    print(chr(ls.index(max(ls))+65))
else:
    print("?")