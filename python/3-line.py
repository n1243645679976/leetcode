class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums.append(1)
        nums = [1] + nums
        ln = len(nums)
        dp = [[0]*ln for i in range(ln)]
        
        for diff in range(2, ln):
            for i in range(ln - diff):
                j = i + diff
                for k in range(i+1, j):
                    # print(i, j, k)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[j] * nums[k])
#        print(dp)   
        return dp[0][-1]
        
            
            