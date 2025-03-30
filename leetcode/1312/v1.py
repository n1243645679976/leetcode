class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        rs = s[::-1]
        dp = [[0]*(len(s)+1) for _ in range(len(s)+1)]
        for i in range(len(s)):
            for j in range(len(s)):
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j], dp[i][j] + (s[i] == rs[j]))
        return len(s) - dp[-1][-1]
            