class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ma = nums[0]
        mi = nums[0]
        ans = nums[0]
        for num in nums[1:]:
            if num < 0:
                ma, mi = mi, ma
            ma = max(num, ma*num)
            mi = min(num, mi*num)
            ans = max(ans, ma)
        return ans