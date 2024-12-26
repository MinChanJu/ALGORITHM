A=int(input())
lis = []
for i in range(0,A):
    B = input().split(' ')
    lis.append(B)
for i in lis:
    print(int(i[0])+int(i[1]))