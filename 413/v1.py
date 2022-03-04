class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 3:
            return 0
        count = 0
        ans = 0
        a0 = nums[0]
        a1 = nums[1]
        for n in nums[2:]:
            a2 = n
            if a2 - a1 == a1 - a0:
                count += 1
            else:
                ans += count * (count+1) // 2
                count = 0
            a0 = a1
            a1 = a2
        ans += count * (count+1)//2
        return ans