class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums = sorted(nums)
        dp = [(0,-1) for j in range(len(nums))]
        for i in range(len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and dp[i][0] < dp[j][0] + 1:
                    dp[i] = (dp[j][0]+1, j)
                
            #print(dp)
        maxl = 0
        maxi = 0
        for i in range(len(nums)):
            if dp[i][0] > maxl:
                maxi = i
                maxl = dp[i][0]
        ans = []
        # print(dp, nums)
        while maxi > -1:
            ans.append(nums[maxi])
            maxi = dp[maxi][1]
        
        return ans
                
            
                    