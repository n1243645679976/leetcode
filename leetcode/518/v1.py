class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        coins = sorted(coins)
        maxj = len(coins)
        dp = [0 for i in range(amount+1)]
        dp[0] = 1
        for coin in coins:
            for i in range(amount-coin+1):
                dp[i+coin] += dp[i]
        return dp[amount]