n=input()
s=set()
for i in range(len(n)):
    for j in range(i,len(n)):
        s.add(n[i:j+1])
print(len(s))