class Solution(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        been = set([0])
        ans = 0
        dist = [abs(x-points[0][0]) + abs(y-points[0][1]) for x, y in points]
        for i in range(len(points)-1):
            minind = 0
            minval = float('inf')
            for j in range(len(points)):
                if j not in been:
                    if minval > dist[j]:
                        minval = dist[j]
                        minind = j
                        
            been.add(minind)
            ans += minval
            for k in range(len(points)):
                if k not in been:
                    dist[k] = min(dist[k], abs(points[k][0] - points[minind][0])+abs(points[k][1] - points[minind][1]))
        return ans
                
        