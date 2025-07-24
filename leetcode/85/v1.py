class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if matrix == []:
            return 0
        lx = len(matrix)
        ly = len(matrix[0])
        countdown = [[0]*ly for i in range(lx)]
        for i in range(0, lx):
            for j in range(0, ly):
                if i == 0:
                    countdown[i][j] = int(matrix[i][j])
                else:
                    countdown[i][j] = 0 if matrix[i][j] == '0' else countdown[i-1][j] + 1
                
        ans = 0
        for i in range(0, lx):
            j = 0
            for j in range(0, ly):
                if j > 0 and countdown[i][j] <= countdown[i][j-1]:
                    continue
                mink = countdown[i][j]
                k = j
                while k < ly:
                    if matrix[i][k] == '1':
                        mink = min(mink, countdown[i][k])
                        ans = max(ans, (k - j + 1) * mink)
                        k += 1
                    else:
                        break
            
        return ans
                
                        
                    
            