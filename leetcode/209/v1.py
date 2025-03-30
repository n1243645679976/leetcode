class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        windowLeft = 0
        windowRight = 0 # not contain (to add)
        accum = 0
        ans = 0
        for windowLeft in range(len(nums)):
            while accum < target:
                if windowRight == len(nums):
                    return ans
                accum += nums[windowRight]
                windowRight += 1
            ans = min(ans, windowRight - windowLeft) if ans > 0 else windowRight - windowLeft
            accum -= nums[windowLeft]
        return ans
            
        
            