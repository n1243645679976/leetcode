class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        su = 0
        d = defaultdict(int)
        d[0] = 1
        ans = 0
        for num in nums:
            su += num
            ans += d[su-k]
            d[su] += 1 
        return ans