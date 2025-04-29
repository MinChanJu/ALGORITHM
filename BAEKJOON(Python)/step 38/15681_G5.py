import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def make_tree(root,tree):
    visit[root] = 1
    for node in graph[root]:
        if visit[node] == 0:
            tree[root].append(node)
            make_tree(node,tree)

def countSubtreeNode(currentNode) :
    size[currentNode] = 1
    for Node in tree[currentNode]:
        countSubtreeNode(Node)
        size[currentNode] += size[Node]

N, R, Q = map(int,input().split())
graph = {i:[] for i in range(1,N+1)}
for _ in range(N-1):
    a, b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
tree = {i:[] for i in range(1,N+1)}
visit = [0]*(N+1)
make_tree(R,tree)
size = [0]*(N+1)
countSubtreeNode(R)
U = []
for _ in range(Q):
    U.append(int(input()))
for i in U:
    print(size[i])