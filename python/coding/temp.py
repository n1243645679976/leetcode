def getint():
    return int(input())
def getfloat():
    return float(input())
def getints():
    return list(map(int, input().split()))
def getfloats():
    return list(map(float, input().split()))

class TrieNode:
    def __init__(self):
        self.isWord = False
        self.next = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()        

    def insert(self, word):
        n = self.root
        for i in word:
            if i not in n.next:
                n.next[i] = TrieNode()
            n = n.next[i]
        n.isWord = True        

    def search(self, word):
        n = self.root
        ans = 0
        for i in word:
            if i not in n.next:
                return ans
            else:
                ans += 1
                n = n.next[i]
        return ans
def inv(a):
    c = [0 for i in range(len(a))]
    for i, k in enumerate(a):
        c[k-1] = i + 1
    return c
from collections import deque
T = getint()
for _t in range(T):
    n, m1, m2 = getints()
    
        