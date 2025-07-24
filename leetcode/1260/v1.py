class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        lx = len(grid[0])
        ly = len(grid)
        r = [[0]*lx for i in range(ly)]
        for x, y in product(range(lx), range(ly)):
            q = y * lx + x
            q += k
            newx = q % lx
            newy = (q // lx) % ly
            r[newy][newx] = grid[y][x]
        return r
            