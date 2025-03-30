class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dp = [[-1]*len(nums) for i in range(len(nums))]
        for i in range(len(nums)):
            dp[i][i] = (nums[i], 0)
        for diff in range(1,len(nums)):
            for i in range(len(nums)-diff):
                dp[i][i+diff] = max((dp[i+1][i+diff][1]+nums[i]     , dp[i+1][i+diff][0]), 
                                    (dp[i][i+diff-1][1]+nums[i+diff], dp[i][i+diff-1][0]))
        #print(dp)
        return dp[0][len(nums)-1][0] >= dp[0][len(nums)-1][1]
                