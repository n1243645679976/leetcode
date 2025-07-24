class Solution(object):
    def splitString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def dfs(ind, tar):
            if ind == len(s):
                return True
            print(ind, tar)
            for i in range(ind+1, len(s)+1):
                q = int(s[ind:i])
                print(s[ind:i], q)
                if q > tar:
                    return False
                if q == tar:
                    flag = dfs(i, q-1)
                    if flag:
                        return True
        
        for i in range(1, len(s)):
            q = int(s[:i])
            print(s[:i], q)
            if q != 0:
                flag = dfs(i, q-1)
                if flag:
                    return True
        return False