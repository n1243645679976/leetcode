class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        l = 1
        r = 1e9
        while l < r:
            mid = (l + r) // 2
            time = sum((pile + mid - 1) // mid for pile in piles)
            #print(mid, time)
            if time > h:
                l = mid + 1
            else:
                r = mid
        return int(l)