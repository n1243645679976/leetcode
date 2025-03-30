class Solution(object):
    def minStartValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        _min = 0
        _sum = 0
        for num in nums:
            _sum += num
            _min = min(_sum, _min)
        return -_min+1 if _min <=0 else 1