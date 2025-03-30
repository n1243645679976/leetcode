class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height) - 1
        ans = max(0, min(height[r], height[l]) * (r - l))
        while l < r:
            if height[l] < height[r]:
                st = height[l]
                while l < r and height[l] <= st:
                    l += 1
                ans = max(ans, min(height[r], height[l]) * (r - l))
            else:
                st = height[r]
                while l < r and height[r] <= st:
                    r -= 1
                ans = max(ans, min(height[r], height[l]) * (r - l))
            #print(height[r], height[l])
        return ans