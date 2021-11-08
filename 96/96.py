class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [-1 for i in range(n+2)]
        dp[0] = 1
        dp[1] = 1
        def dq(c):
            if dp[c] >= 0:
                return dp[c]
            _sum = 0
            for i in range(c):
                _sum += dq(i) * dq(c-i-1)
                #print(_sum, i, c-i-1)
            dp[c] = _sum
            return dp[c]
        dq(n)
        #print(dp)
        return dp[n]
                