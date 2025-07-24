class UnionFind():
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    def union(self, a, b):
        if self.find(a) != self.find(b):
            self.parent[self.parent[b]] = self.parent[a]
    def find(self, a):
        if self.parent[a] == a:
            return a
        else:
            self.parent[a] = self.find(self.parent[a])
            return self.parent[a]
    def check_redundant(self, a, b):
        return self.find(a) == self.find(b)

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        uf = UnionFind(len(edges)+1)
        for s, e in edges:
            if uf.check_redundant(s, e):
                ans = [s, e]
            uf.union(s, e)
        return ans
        