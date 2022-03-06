class Solution(object):
    def countOrders(self, n):
        """
        :type n: int
        :rtype: int
        """
        ans = 1
        for i in range(1, n+1):
            ans *= i
            ans %= 1e9 + 7
        for i in range(1, 2*n, 2):
            ans *= i
            ans %= 1e9 +7
        return int(ans)