class Solution(object):
    def numOfPairs(self, nums, target):
        """
        :type nums: List[str]
        :type target: str
        :rtype: int
        """
        ans = 0
        for a, b in permutations(nums, 2):
            if target == a+b:
                ans += 1
        return ans