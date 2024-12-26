import sys
input = sys.stdin.readline

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
    
    def count(self, string):
        curr_node = self.head.children[string[0]]
        cnt = 1

        for char in string[1:]:
            if curr_node.data != None or len(curr_node.children) > 1: cnt += 1
            curr_node = curr_node.children[char]
        
        return cnt

while 1:
    try:
        N = int(input())
    except:
        break
    
    dictionary = [input().rstrip() for _ in range(N)]
    trie = Trie()
    for word in dictionary:
        trie.insert(word)
    
    average = sum([trie.count(word) for word in dictionary])/N
    print(f"{average:.2f}")