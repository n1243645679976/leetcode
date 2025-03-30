class Solution(object):
    def smallestGoodBase(self, n):
        """
        :type n: str
        :rtype: str
        """
        _len = 0
        _n = int(n)
        n = int(n)
        while _n:
            _n >>= 1
            _len += 1
        def cal(base):
            k = 0
            for i in range(_len):
                k *= base
                k += 1
            return k
        while _len:
            l = 2
            r = int(n) - 1
            while l <= r:
                mid = (l+r) // 2
                k = cal(mid)
                #print(k, n, mid)
                if k == n:
                    return str(mid)
                elif k < n:
                    l = mid + 1
                else:
                    r = mid - 1
            _len -= 1
            
            
            