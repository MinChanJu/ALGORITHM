sum,hak=0,0
score={'A+':4.5,'A0':4.0,'B+':3.5,'B0':3.0,'C+':2.5,'C0':2.0,'D+':1.5,'D0':1.0,'F':0.0}
for i in range(0,20):
    A,B,C=input().split()
    if C=='P':
        continue
    sum+=float(B)
    hak+=score[C]*float(B)
sc=hak/sum
print("%.6f"%sc)