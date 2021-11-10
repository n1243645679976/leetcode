class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        prices.append(-1)
        ans = 0
        _min = 10000
        for i in range(len(prices)-1):
            if prices[i] < _min:
                _min = prices[i]
            if prices[i+1] < prices[i]:
                if prices[i] >= _min:
                    ans += prices[i] - _min
                    _min = 100000
        return ans
                