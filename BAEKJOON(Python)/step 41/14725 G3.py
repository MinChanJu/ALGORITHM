import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

class Node:
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = dict()

class Trie:
    def __init__(self):
        self.head = Node(None)
    
    def insert(self, string):
        curr_node = self.head
        
        for word in string:
            if word not in curr_node.children:
                curr_node.children[word] = Node(word)
            curr_node = curr_node.children[word]
        
        curr_node.data = string
    
    def search(self, string):
        curr_node = self.head

        for char in string:
            if char in curr_node.children:
                curr_node = curr_node.children[char]
            else:
                return False

        if curr_node.data is not None:
            return True
    
    def visualize(self, level, curr_node):
        if not level:
            curr_node = self.head
        for child in sorted(curr_node.children.keys()):
            print("--" * level, end="")
            print(child)
            self.visualize(level + 1, curr_node.children[child])

trie = Trie()
N = int(input())
for _ in range(N):
    load = input().rstrip().split()[1:]
    trie.insert(load)
trie.visualize(0, None)