H,M=input().split(' ')
C=int(input())
H,M=int(H),int(M)
M+=C
while 1:
    if M>=60:
        M-=60
        H+=1
    else:
        break
if H>=24:
    H-=24
print(H,M)
