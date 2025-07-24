class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = 0
        mi = prices[0]
        for p in prices:
            if p > mi:
                ans = max(ans, p - mi)
            else:
                mi = p
        return ans