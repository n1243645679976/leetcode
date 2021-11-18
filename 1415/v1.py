class Solution(object):
    def getHappyString(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        ans = []
        self.k = k
        def dfs(_n, l):
            # print(_n, l)
            if _n == n:
                self.k -= 1
                if self.k == 0:
                    return ''.join(l)
                return -1
            for i in 'abc':
                if l[-1] == i:
                    continue
                else:
                    l.append(i)
                    q = dfs(_n+1, l)
                    if self.k == 0:
                        return q
                    l.pop()
            return -1        
        l = dfs(1, ['a'])
        if l != -1:
            return l
        l = dfs(1, ['b'])
        if l != -1:
            return l
        l = dfs(1, ['c'])
        if l != -1:
            return l
        return ""
            