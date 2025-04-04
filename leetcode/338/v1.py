class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = [0]
        for i in range(1,n+1):
            ans.append(ans[i>>1]+(i&1))
        return ans