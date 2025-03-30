class Solution(object):
    def kWeakestRows(self, mat, k):
        """
        :type mat: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        r = [(sum(m), i) for i, m in enumerate(mat)]
        return [i for m, i in sorted(r)][:k]