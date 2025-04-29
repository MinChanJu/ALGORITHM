import sys
n=int(sys.stdin.readline())
ls=set()
for _ in range(n):
    a,b=sys.stdin.readline().split()
    if b=='enter':
        ls.add(a)
    else:
        ls.remove(a)
ls=sorted(list(ls))
ls=reversed(ls)
for i in ls:
    print(i)