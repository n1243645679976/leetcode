class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        ans = 0
        q = num
        while num:
            ans <<= 1
            ans += 1
            num >>= 1
        return ans - q