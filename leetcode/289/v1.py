class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        lives = []
        dies = []
        li = len(board)
        lj = len(board[0])
        for i, j in product(range(li), range(lj)):
            count = 0
            for di, dj in product(range(-1, 2), range(-1, 2)):
                if check(i, di, li) and check(j, dj, lj):
                    count += (board[i+di][j+dj] != 0)
            if board[i][j] == 0:
                if count == 3:
                    lives.append((i, j))
            else:
                if count < 3 or count > 4:
                    dies.append((i, j))
        
        for i, j in lives:
            board[i][j] = 1
        for i, j in dies:
            board[i][j] = 0
        
                