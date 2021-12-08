class Solution(object):
    def numOfPairs(self, nums, target):
        """
        :type nums: List[str]
        :type target: str
        :rtype: int
        """
        return sum((target == a+b) for a, b in permutations(nums, 2))