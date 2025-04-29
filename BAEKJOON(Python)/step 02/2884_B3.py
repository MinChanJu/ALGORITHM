H,M=input().split(' ')
H,M=int(H),int(M)
if M>=45:
    print(H,M-45)
elif M<45:
    if H==0:
        H=23
        print(H,15+M)
    else:
        print(H-1,15+M)