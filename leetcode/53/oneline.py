class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return max(itertools.accumulate(nums, lambda x,y: max(x+y,y)))
        