class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points)
        ans = 0
        mie = float('inf')
        for s, e in points:
            if s > mie:
                ans += 1
                mie = e
            else:
                mie = min(e, mie)
        return ans+1