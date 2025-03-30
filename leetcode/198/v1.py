class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0, 0, 0]
        for num in nums:
            dp.append(max(dp[-2], dp[-3]) + num)
        return max(dp[-1], dp[-2])