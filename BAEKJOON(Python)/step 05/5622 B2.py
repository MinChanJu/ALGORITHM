N=input()
sum=0
for i in range(0,len(N)):
    if 65<=ord(N[i])<=79:
        sum+=(ord(N[i])-65)//3+3
    elif  84<=ord(N[i])<=86:
        sum+=9
    elif 80<=ord(N[i])<=83:
        sum+=8
    elif 87<=ord(N[i])<=90:
        sum+=10
print(sum)