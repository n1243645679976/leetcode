class Trie():
    def __init__(self):
        self.root = {}
    
    def update(self, w):
        node = self.root
        for i, c in enumerate(w):
            node = node.setdefault(c, {})
            node.setdefault('ans', 0)
            node['ans'] += 1
        
    def search(self, w):
        node = self.root
        ans = 0
        for i, c in enumerate(w):
            if c not in node:
                break
            node = node[c]
            ans += node.get('ans', 0)
        return ans
                

class TrieNode():
    def __init__(self):
        self.children = {}
        self.refs = 0
        self.wordind = -1
    
    def update(self, w, wordind):
        # w: iter(word)
        c = next(w, None)
        if c == None:
            self.wordind = wordind
            return
        elif c not in self.children:
            self.children[c] = TrieNode()
        self.refs += 1
        self.children[c].update(w, wordind)
        
    def removeword(self, w):
        # w: iter(word)
        c = next(w, None)
        if c == None:
            self.wordind = -1
            return
        self.refs -= 1
        self.children[c].removeword(w)
        
