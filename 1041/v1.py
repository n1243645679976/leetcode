class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        dir = [(0, 1), (1, 0), (0, -1), (-1, 0)] # x, y, right+1, left-1
        x, y = 0, 0
        nowdir = 0
        for i in instructions:
            if i == 'G':
                dx, dy = dir[nowdir & 3]
                x += dx
                y += dy
            elif i == 'L':
                nowdir -= 1
            else:
                nowdir += 1
        return (nowdir & 3 != 0) or ((nowdir & 3 == 0) and x == 0 and y == 0) 
            
            
            