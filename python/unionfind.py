class UnionFind():
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    def unite(self, a, b):
        assert 0 <= a < self.n and 0 <= b < self.n
        if self.find(a) != self.find(b):
            mx = max(self.parent[a], self.parent[b])
            self.parent[self.parent[b]] = mx
            self.parent[self.parent[a]] = mx
    def find(self, a):
        assert 0 <= a < self.n
        if self.parent[a] == a:
            return a
        else:
            self.parent[a] = self.find(self.parent[a])
            return self.parent[a]
    def maxunion(self):
        mac = 0
        count = Counter()
        for i in self.parent:
            self.find(i)
            count[self.parent[i]] += 1
            mac = max(mac, count[self.parent[i]])
        return mac

class UnionFind():
    def __init__(self):
        self.parent = {}
    def unite(self, a, b):
        if self.find(a) != self.find(b):
            self.parent[self.parent[b]] = self.parent[a]
    def find(self, a):
        if a not in self.parent:
            self.parent[a] = a
        if self.parent[a] != a:
            self.parent[a] = self.find(self.parent[a])
        return self.parent[a]
    def maxunion(self):
        mac = 0
        count = Counter()
        for i in self.parent:
            self.find(i)
            count[self.parent[i]] += 1
            mac = max(mac, count[self.parent[i]])
        return mac