class Solution(object):
    def swimInWater(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        lx = len(grid)
        ly = len(grid[0])
        dp = [[-1]*ly for i in range(lx)]
        update = deque([[0,0]])
        dp[0][0] = grid[0][0]
        while update:
            x, y = update.popleft()
            for dx, dy in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                if x + dx >= 0 and x + dx < lx and y + dy >= 0 and y + dy < ly:
                    if dp[x+dx][y+dy] < 0:
                        dp[x+dx][y+dy] = max(dp[x][y], grid[x+dx][y+dy])
                        update.append([x+dx, y+dy])
                    else:
                        if max(dp[x][y], grid[x+dx][y+dy]) < dp[x+dx][y+dy]:
                            dp[x+dx][y+dy] = max(dp[x][y], grid[x+dx][y+dy])
                            update.append([x+dx, y+dy])
        print(dp)
        return dp[-1][-1]