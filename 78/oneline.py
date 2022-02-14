class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return [j for i in range(len(nums)+1) for j in combinations(nums, i) ]