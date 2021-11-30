class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        return min(abs(s[::2].count('0') + s[1::2].count('1')), abs(s[::2].count('1') + s[1::2].count('0')))