n=int(input())
for i in range(0,n):
    C=int(input())
    print(C//25,end=' ')
    C=C%25
    print(C//10,end=' ')
    C=C%10
    print(int(C//5),end=' ')
    C=C%5
    print(C)