class Solution(object):
    def singleNonDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = 0
        r = len(nums)-1
        n = r
        mid = r // 2
        while True:
            if mid == n:
                return nums[mid]
            if mid > r:
                return nums[r]
            if mid < l:
                return nums[l]
            if mid & 1: # odd
                if nums[mid] == nums[mid+1]:
                    r = mid - 1
                    mid = (l+r)//2
                else:
                    l = mid + 1
                    mid = (l+r)//2
            else:
                if nums[mid] == nums[mid+1]:
                    l = mid + 1
                    mid = (l+r)//2
                else:
                    r = mid - 1
                    mid = (l+r)//2
        return nums[mid]
        