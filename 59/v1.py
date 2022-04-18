class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        tot = n * n
        def valid(a, b, ans):
            if a >= 0 and b >= 0 and a < n and b < n:
                if ans[a][b] == 0:
                    return True
            return False
        ans = [[0 for i in range(n)] for j in range(n)]
        x, y = 0, -1
        dx, dy = 0, 1
        count = 1
        while tot:
            if valid(x+dx, y+dy, ans):
                ans[x+dx][y+dy] = count
            else:
                temp = dy
                dy = -dx
                dx = temp
                ans[x+dx][y+dy] = count
            x += dx
            y += dy
            tot -= 1
            count += 1
        return ans