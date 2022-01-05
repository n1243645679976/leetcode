import copy
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        temp = []
        ans = []
        ls = len(s)
        dp = [[0]* (ls+1) for _ in range(ls+1)]
        def dfs(start):
            if start == ls:
                ans.append(temp)
                return
            for i in range(start+1, ls+1):
                if dp[start][i] > 0:
                    temp.append(s[start:i])
                    dp[start][i] = 1
                    dfs(i)
                    temp.pop()
                    continue
                elif dp[start][i] < 0:
                    continue
                rs = s[i-1:start-1:-1] if start > 0 else s[i-1::-1]
                
                # print(start, i, rs)
                if s[start:i] == rs:
                    temp.append(s[start:i])
                    dp[start][i] = 1
                    dfs(i)
                    temp.pop()
                else:
                    dp[start][i] = -1
        dfs(0)
        return ans
                    
                    
                
                