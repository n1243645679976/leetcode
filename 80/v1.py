class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        same = False
        j = 1
        while j < len(nums):
            if nums[j] == nums[j-1]:
                if not same:
                    same = True
                    j += 1
                else:
                    del nums[j]
            else:
                j += 1
                same = False