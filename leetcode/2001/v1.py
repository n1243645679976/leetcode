def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)

class Solution:
    def interchangeableRectangles(self, rs: List[List[int]]) -> int:
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        q = defaultdict(int)
        for w, h in rs:
            f = gcd(w, h)
            q[(w//f, h//f)]+=1
        from math import comb
        return sum(comb(_q, 2) if _q > 1 else 0 for _q in q.values())
        