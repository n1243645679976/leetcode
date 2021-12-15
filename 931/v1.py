class Solution(object):
    def minFallingPathSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        for i in range(1, len(matrix)):
            for j in range(len(matrix[0])):
                ma = [matrix[i-1][j]]
                if j > 0:
                    ma.append(matrix[i-1][j-1])
                if j < len(matrix[0]) - 1:
                    ma.append(matrix[i-1][j+1])
                matrix[i][j] = min(ma) + matrix[i][j]
        return min(matrix[-1])
            