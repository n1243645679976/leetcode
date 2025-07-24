class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        ln = len(grid)
        ans = [0] * ln
        
        #print(ans)
        for i in range(ln):
            q = []
            for j in range(ln):
                ans[j] += grid[i][j]
            r = sorted(ans)
            for j in range(ln):
                ans[j] = r[1] if r[0] == ans[j] and ln > 1 else r[0]
            #print(ans)
        return min(ans)
            
                    
            
        