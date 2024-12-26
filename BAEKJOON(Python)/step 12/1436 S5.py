N=int(input())
ls,i=[],0
while 1:
    if '666' in str(i):
        ls.append(i)
    if len(ls)>N:
        break
    i+=1
print(ls[N-1])