class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        #print('{:b} {:b}'.format(n, -n))
        return (n & -n) == n if n >= 1 else False