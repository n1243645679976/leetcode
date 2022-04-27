class UnionFind():
    def __init__(self):
        self.parent = {}
    def union(self, a, b):
        if self.find(a) != self.find(b):
            self.parent[self.parent[b]] = self.parent[a]
    def find(self, a):
        if a not in self.parent:
            self.parent[a] = a
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]
    
class Solution(object):
    def smallestStringWithSwaps(self, s, pairs):
        """
        :type s: str
        :type pairs: List[List[int]]
        :rtype: str
        """
        p_uf = UnionFind()
        for a, b in pairs:
            p_uf.union(a, b)
        
        groups = defaultdict(list)
        for i in range(len(s)):
            p = p_uf.find(i)
            groups[p].append((s[i], i))
        
        ans = ['0' for i in range(len(s))]
        for k in groups:
            q = sorted(groups[k])
            for (c, _), (_, i) in zip(q, groups[k]):
                ans[i] = c
        return ''.join(ans)
            
            
        
        