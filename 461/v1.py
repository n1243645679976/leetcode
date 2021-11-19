class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        a = x ^ y
        ans = 0
        while a:
            ans += (a&1)
            a >>= 1
        return ans