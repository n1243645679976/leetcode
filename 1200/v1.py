class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """
        q = sorted(arr)
        mi = 1e7
        for i in range(1, len(arr)):
            mi = min(mi, q[i] - q[i-1])
        ans = []
        for i in range(1, len(arr)):
            if mi == q[i] - q[i-1]:
                ans.append([q[i-1], q[i]])
        return ans