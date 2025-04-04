from sortedcontainers import SortedList
class KthLargest(object):

    def __init__(self, k, nums):
        """
        :type k: int
        :type nums: List[int]
        """
        nums.sort()
        self.nums = SortedList(nums[-k:])
        self.k = k

    def add(self, val):
        """
        :type val: int
        :rtype: int
        """
        self.nums.add(val)
        if len(self.nums) > self.k:
            self.nums.pop(0)
        return self.nums[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)