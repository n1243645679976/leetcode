class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        q = set()
        for n in nums:
            if n in q:
                return n
            q.add(n)
        return -1