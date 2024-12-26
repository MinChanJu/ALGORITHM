n=input()
cro_alp= ['dz=','c=','z=','c-','d-','lj','nj','s=']
for i in cro_alp:
    if n.find(i)!=-1:
        n=n.replace(i,'0')
print(len(n))