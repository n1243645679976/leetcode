class Solution:
    def minimumDeletions(self, s: str) -> int:
        dp = [[1000000]*(len(s)+1) for i in range(2)]
        dp[0][0] = 0
        dp[1][0] = 0
        for i in range(len(s)):
            dp[0][i+1] = dp[0][i] + (s[i] == 'b')
            dp[1][i+1] = min(dp[1][i] + (s[i] == 'a'), dp[0][i] + (s[i] == 'a'))
        # print(dp)
        return min(dp[0][-1], dp[1][-1])