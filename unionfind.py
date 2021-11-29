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