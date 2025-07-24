from sortedcontainers import SortedList
class Solution(object):
    def minimumDeviation(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sl = SortedList()
        
        for num in nums:
            if num & 1 == 1:
                sl.add(num<<1)
            else:
                sl.add(num)
        
        ans = sl[-1] - sl[0]
        while sl[-1] & 1 == 0:
            q = sl.pop()
            sl.add(q>>1)
            ans = min(ans, sl[-1] - sl[0])
        return ans