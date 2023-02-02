class Trie:
    def __init__(self):
        self.trie = lambda: defaultdict(Trie)
    def insert(self, word):
        trie = self.trie
        for w in word:
            trie = trie[w]
    def search(self, word):
        trie = self.trie
        for w in word:
            if w not in trie:
                return -1
        
        
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

    def search(self, word: str) -> bool:
        n = self.root
        ans = 0
        for i in word:
            if i not in n.next:
                return ans
            else:
                ans += 1
                n = n.next[i]
        return ans
