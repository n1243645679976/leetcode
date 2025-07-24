class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ln = len(nums)
        maxdiff = len(nums) - 1
        nums = sorted(list(set(nums)))
        winl = 0
        ans = 0
        for i, n in enumerate(nums):
            while nums[winl] < nums[i] - maxdiff:
                winl += 1
            ans = max(ans, i - winl)
        return ln - ans - 1
        