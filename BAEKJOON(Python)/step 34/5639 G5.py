import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

preorder = []
while True:
    try:
        num = int(input())
        preorder.append(num)
    except:
        break

def post(ls):
    node = ls[0]
    L = 1
    R = len(ls)
    for i in range(1, len(ls)):
        if node < ls[i]:
            R = i
            break
    Lls = ls[L:R]
    if Lls:
        post(Lls)
    Rls = ls[R:]
    if Rls:
        post(Rls)
    print(node)

post(preorder)