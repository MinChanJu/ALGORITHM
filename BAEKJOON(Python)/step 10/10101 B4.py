angle=[]
sum=0
for i in range(0,3):
    n=int(input())
    angle.append(n)
    sum+=n
if sum!=180:
    print("Error")
elif angle[0]==angle[1]==angle[2]:
    print("Equilateral")
elif angle[0]!=angle[1] and angle[2]!=angle[1] and angle[0]!=angle[2]:
    print("Scalene")
else:
    print("Isosceles")