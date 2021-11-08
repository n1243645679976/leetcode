class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        q = set()
        for num in nums[:k+1]:
            if num in q:
                return True
            q.add(num)
        for i in range(k+1, len(nums)):
            q.remove(nums[i-k-1])
            if nums[i] in q:
                return True
            q.add(nums[i])
        return False
            
            