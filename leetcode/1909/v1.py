class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        now = [-1]
        flag = True
        pre = nums[0]
        for i in range(1, len(nums)):
            # print(nums[i], pre)
            if i < 2:
                if nums[i] <= pre:
                    pre = nums[i]
                    flag = False
                else:
                    pre = nums[i]
            elif nums[i] <= pre:
                if not flag:
                    return False
                if nums[i] <= nums[i-2]:
                    pre = nums[i-1]
                else:
                    pre = nums[i]
                flag = False
            else:
                pre = nums[i]
                
        return True