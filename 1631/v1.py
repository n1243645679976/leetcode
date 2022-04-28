class Solution(object):
    def minimumEffortPath(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: int
        """
        lx = len(heights)
        ly = len(heights[0])
        been = set((0, 0))
        bfs = [(0, (0, 0))]
        while bfs:
            maxdiff, (x, y) = heapq.heappop(bfs)
            if (x, y) in been:
                continue
            been.add((x, y))
            if (x, y) == (lx-1, ly-1):
                return maxdiff
            for nx, ny in [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]:
                if 0<=nx<lx and 0 <=ny<ly and (nx, ny) not in been:
                    heapq.heappush(bfs, (max(maxdiff, abs(heights[x][y] - heights[nx][ny])), (nx, ny)))
        
                    
                    
                    