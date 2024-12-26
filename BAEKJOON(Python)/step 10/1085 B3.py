x,y,w,h=map(int,input().split())
ls=[w-x,x,y,h-y]
ls.sort(key=abs)
print(abs(ls[0]))