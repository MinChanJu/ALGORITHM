import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))
inorder_id = [0] * (n+1)

for i in range(n):
    inorder_id[inorder[i]] = i

def preorder(IS, IE, PS, PE):
    if IS > IE or PS > PE: return
    current = postorder[PE]
    print(current, end=" ")
    L = inorder_id[current] - IS
    R = IE - inorder_id[current]
    preorder(IS, IS+L-1, PS, PS+L-1)
    preorder(IE-R+1, IE, PE-R, PE-1)

preorder(0, n-1, 0, n-1)