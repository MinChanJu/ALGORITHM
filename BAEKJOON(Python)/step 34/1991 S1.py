import sys
input=sys.stdin.readline
N=int(input())
tree={chr(i):[] for i in range(65,65+N)}
for i in range(N):
    a,b,c=input().split()
    tree[a]=[b,c]

def preorder(root):
    if root != '.':
        print(root, end='') 
        preorder(tree[root][0])  
        preorder(tree[root][1])  

def inorder(root):
    if root != '.':
        inorder(tree[root][0])
        print(root, end='')  
        inorder(tree[root][1])  

def postorder(root):
    if root != '.':
        postorder(tree[root][0])
        postorder(tree[root][1]) 
        print(root, end='')
preorder('A')
print('')
inorder('A')
print('')
postorder('A')