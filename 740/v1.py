class Solution(object):
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        c = Counter(nums)
        maxkey = max(nums)
        minkey = min(nums)
        dp = [0 for i in range(maxkey+3)]
        for i in range(minkey, maxkey+1):
            dp[i] = max(dp[i-1], dp[i-2]+c[i] * i)
        #print(dp)
        return dp[maxkey]