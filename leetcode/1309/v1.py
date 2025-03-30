class Solution(object):
    def freqAlphabets(self, s):
        """
        :type s: str
        :rtype: str
        """
        for i in range(10, 27):
            k = chr(96+i)
            s = s.replace(str(i)+'#', k)
        for i in range(1, 10):
            k = chr(96+i)
            s = s.replace(str(i), k)
        return s