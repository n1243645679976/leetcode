# TLE -> update, query 數值錯了, < 0
class BIT:
    def __init__(self, n):
        # valid input: [0, n]
        self.sums = [0] * (n+3)
    
    def update(self, i, delta):
        # update >=i with delta
        i += 2
        while i < len(self.sums):
            self.sums[i] += delta
            i += i & (-i)
    def _query(self, i):
        # get (0, i]
        i += 2
        res = 0
        while i > 0:
            res += self.sums[i]
            i -= i & (-i)
        return res
    
    def query(self, i, j =None):
        # [0, i] or [i, j]
        if j == None:
            return self._query(i)
        else:
            assert j >= i
            return self._query(j) - self._query(i-1)
        
    def update_interval(self, a, b, delta):
        # update [b, a]
        self.update(a+1, -delta)
        self.update(b, delta)
    
    
class Solution:
    def goodTriplets(self, A, B):
        d = {x: i for i, x in enumerate(A)}
        n = len(A)
        arr = [d[B[i]] for i in range(n)]

        BIT1, BIT2, ans = BIT(n), BIT(n), 0
        for i in arr:
            ans += BIT2.query(i)
            BIT1.update(i + 1, 1)
            less = BIT1.query(i)
            BIT2.update(i + 1, less)
        return ans