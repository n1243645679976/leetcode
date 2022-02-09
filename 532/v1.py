class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k == 0:
            ans = 0
            q = Counter(nums)
            for _q in q:
                ans += q[_q] >= 2
            return ans
        else:
            q = set(nums)
            ans = 0
            for n in q:
                ans += (n+k) in q
            return ans