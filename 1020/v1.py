class Solution(object):
    def numEnclaves(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        lx = len(grid)
        ly = len(grid[0])
        def dfs(x, y):
            if grid[x][y] == 0:
                return
            grid[x][y] = 0
            if x > 0:
                dfs(x-1, y)
            if x < lx - 1:
                dfs(x+1, y)
            if y > 0:
                dfs(x, y-1)
            if y < ly - 1:
                dfs(x, y+1)
            
        for x in range(lx):
            dfs(x, 0)
            dfs(x, ly - 1)
        for y in range(ly):
            dfs(0, y)
            dfs(lx - 1, y)
        return sum([sum(grid[i]) for i in range(lx)])
            