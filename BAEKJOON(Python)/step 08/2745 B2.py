ls={}
for i in range(65,91):
    ls[chr(i)]=i-55
N,B=input().split()
B_2=0
for i in range(len(N)-1,-1,-1):
    if N[i] in ls:
        B_2+=ls[N[i]]*(int(B)**(len(N)-i-1))
    else:
        B_2+=int(N[i])*(int(B)**(len(N)-i-1))
print(B_2)