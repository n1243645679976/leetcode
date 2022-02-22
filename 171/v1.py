class Solution(object):
    def titleToNumber(self, columnTitle):
        """
        :type columnTitle: str
        :rtype: int
        """
        d = {}
        for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
            d[i] = ord(i) - 64
        ans = 0
        for c in columnTitle:
            ans *= 26
            ans += d[c]
        return ans
            