class Solution(object):
    def findTheDistanceValue(self, arr1, arr2, d):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :type d: int
        :rtype: int
        """
        return sum(all(abs(a1-a2) > d for a2 in arr2) for a1 in arr1)