class Solution(object):
    def maxScoreSightseeingPair(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        m = -100
        ans = -100
        for i in range(1, len(A)):
            if A[i-1] + i-1 > m:
                m = A[i-1] + i - 1
            if A[i] - i + m > ans:
                ans = A[i] - i + m
                
        return ans