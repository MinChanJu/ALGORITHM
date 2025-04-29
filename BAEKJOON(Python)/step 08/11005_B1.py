ls={}
for i in range(65,91):
    ls[i-55]=chr(i)
N,B=map(int,input().split())
m=[]
nin=''
while N!=0:
    m.insert(0,N%B)
    N=N//B
for i in range(0,len(m)):
    if m[i] in ls:
        nin+=ls[m[i]]
    else:
        nin+=str(m[i])
print(nin)