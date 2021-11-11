class Solution(object):
    def maxUncrossedLines(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        dp = [[0 for i in range(len(nums2)+1)] for j in range(len(nums1)+1)]
        for i in range(1, len(nums1)+1):
            for j in range(1, len(nums2)+1):
                if i != 0:
                    if dp[i-1][j]> dp[i][j]:
                        dp[i][j] = dp[i-1][j]
                if j != 0:
                    if dp[i][j-1] > dp[i][j]:
                        dp[i][j] = dp[i][j-1]
                if nums1[i-1] == nums2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
            # print(dp)
        return dp[len(nums1)][len(nums2)]