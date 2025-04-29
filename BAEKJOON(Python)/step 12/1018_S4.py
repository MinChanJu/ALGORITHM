ch=['BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB','BWBWBWBW','WBWBWBWB']
N,M=map(int,input().split())
ls,lk=[],[]
for i in range(0,N):
    ls.append(input())
for i in range(0,N-7):
    for j in range(0,M-7):
        res=ls[i:i+8]
        sum=0
        for k in range(0,8):
            res[k]=res[k][j:j+8]
        for k in range(0,8):
            for t in range(0,8):
                if res[k][t]!=ch[k][t]:
                    sum+=1
        if sum>32:
            sum=64-sum
        lk.append(sum)
print(min(lk))