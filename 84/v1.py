class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        a = [(-1, -1)]
        ans = heights[0]
        for i, h in enumerate(heights):
            r = i
            while a[-1][0] > h:
                r = a[-1][1]
                ans = max(ans, a[-1][0] * (i - r))
                a.pop()
            a.append((h, r))
        for q in a:
            ans = max(ans, q[0] * (i+1 - q[1]))
        return ans