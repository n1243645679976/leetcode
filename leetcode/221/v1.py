class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        for i in range(len(matrix[0])):
            matrix[0][i] = int(matrix[0][i])
        for i in range(1, len(matrix)):
            for j in range(len(matrix[0])):
                matrix[i][j] = int(matrix[i-1][j]) + 1 if matrix[i][j] != '0' else 0
        ans = 0
        #print(matrix)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                minh = matrix[i][j]
                for k in range(j, len(matrix[0])):
                    if matrix[i][k] < minh:
                        minh = matrix[i][k]
                    if minh <= k-j and matrix[i][k] == 0:
                        break
                    ans = max(ans, min(minh, (k-j+1)))
                #print(minh, k, j, i, ans)
        return ans*ans
                
                
        