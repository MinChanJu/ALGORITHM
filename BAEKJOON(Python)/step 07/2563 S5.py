board=[]
for i in range(0,100):
    ls=[]
    for j in range(0,100):
        ls.append(0)
    board.append(ls)
n=int(input())
for i in range(0,n):
    a,b=map(int,input().split())
    for j in range(a,a+10):
        for k in range(b,b+10):
            board[k][j]=1
count=0
for i in board:
    count+=i.count(1)
print(count)