class Solution:
    def numTilings(self, n: int) -> int:
        dp = [[0] * (n+1) for i in range(2)]
        dp[0][0] = 1
        for i in range(1, n+1):
            dp[0][i] = dp[0][i-2] + dp[0][i-1] + dp[1][i-1]
            dp[1][i] = dp[0][i-2] * 2 + dp[1][i-1]
            dp[0][i] %= 1000000007
            dp[1][i] %= 1000000007
        return dp[0][n]
        