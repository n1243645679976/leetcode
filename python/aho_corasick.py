class aho_corasick_node:
    def __init__(self):
        self.next = defaultdict(aho_corasick_node)
        self.end = 0
        self.fail = None
        self.used = False
        
class aho_corasick:
    def __init__(self):
        self.trie = aho_corasick_node()
    def insert(self, word):
        trie = self.trie
        for c in word:
            trie = trie.next[c]
        trie.end += 1
    def build(self):
        # 用bfs從淺到深設上個suffix node
        bfs = deque([self.trie])
        while bfs:
            node = bfs.popleft()
            for c, nnode in node.next.items():
                if node == self.trie:
                    nnode.fail = self.trie
                else:
                    ptr = node.fail
                    # 往ptr回走，直到有c為下一個
                    while ptr != self.trie and c not in ptr.next:
                        ptr = ptr.fail
                    # 避免root沒有c
                    if c in ptr.next:
                        ptr = ptr.next[c]
                    nnode.fail = ptr
                bfs.append(nnode)
    def solve(self, word):
        ans = 0
        trie = self.trie
        for c in word:
            # 從trie回走，直到有c為下一個
            while trie != self.trie and c not in trie.next:
                trie = trie.fail
            # 避免root沒有c
            if c in trie.next:
                trie = trie.next[c]
            tmp = trie
            while tmp != self.trie and tmp.used == False:
                ans += tmp.end
                tmp.used = True
                tmp = tmp.fail
        return ans