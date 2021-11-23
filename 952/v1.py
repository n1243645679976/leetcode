class UF():
    def __init__(self, n, nums):
        self.parent = defaultdict(int)
        self.nums = nums
    def find(self, u):
        if u not in self.parent:
            self.parent[u] = u
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    def union(self, u, v):
        if self.find(u) != self.find(v):
            self.parent[self.parent[v]] = self.parent[u]
    def count(self):
        # print(self.parent, self.nums)
        countdic = defaultdict(int)
        for num in self.nums:
            countdic[self.find(num)]+=1
            
        return max(countdic.values())
        
class Solution(object):
    def largestComponentSize(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxnum = max(nums)
        
        p = [i for i in range(maxnum+1)]
        for j in range(2, maxnum+1):
            if p[j] != j:
                continue
            for k in range(j*j, maxnum+1, j):
                p[k] = j
                
        def get_factors(q):
            while p[q] != q:
                yield p[q]
                q /= p[q]
            yield q

        uf = UF(maxnum+1, nums)
        uf.p = p
        for num in nums:
            for f in get_factors(num):
                uf.union(f, num)
        return uf.count()
        
            