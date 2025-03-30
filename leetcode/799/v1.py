class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        dp = [[0 for i in range(j+1)] for j in range(query_row+1)]
        dp[0][0] = poured
        for i in range(1, query_row+1):
            for j in range(i+1):
                if j != i and dp[i-1][j] >= 1:
                    dp[i][j] += (dp[i-1][j] - 1) / 2
                if j != 0 and dp[i-1][j-1] >= 1:
                    dp[i][j] += (dp[i-1][j-1] - 1) / 2
        return dp[query_row][query_glass] if dp[query_row][query_glass] <= 1 else 1