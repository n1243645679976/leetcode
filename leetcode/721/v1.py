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
    def ans(self, name):
        ans = defaultdict(list)
        _ans = []
        for k in self.parent.keys():
            ans[self.find(k)].append(k)
        for k in ans.keys():
            _ans.append([name[k]] + sorted(ans[k]))
        return _ans
            
            
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        name = {}
        uf = UnionFind()
        for a in accounts:
            for q in a[1:]:
                name[q] = a[0]
                uf.union(a[1], q)
        return uf.ans(name)