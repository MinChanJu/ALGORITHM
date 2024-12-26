S=input()
alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
ls=[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]
for i in range(0,26):
    if alphabet[i] in S:
        ls[i]=S.index(alphabet[i])
for i in range(0,26):
    print(ls[i],end=' ')