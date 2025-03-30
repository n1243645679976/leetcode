class Solution:
    def minimumDistance(self, word: str) -> int:
        def dist(a, b):
            if a == '':
                return 0
            a1 = abs(ord(a) - 65) 
            b1 = abs(ord(b) - 65)
            a1 = (a1 // 6, a1 % 6)
            b1 = (b1 // 6, b1 % 6)
            d = abs(a1[0] - b1[0]) + abs(a1[1] - b1[1])
            #print(a, b, d)
            return d
        lw = len(word)
        dp = [defaultdict(lambda :99999999) for i in range(lw)]
        dp[0][(word[0], '')] = 0
        for i in range(1, lw):
            for leftHand, rightHand in dp[i-1].keys():
                dp[i][(word[i], rightHand)] = \
                        min(dp[i-1][(leftHand, rightHand)] + dist(leftHand, word[i]), dp[i][(word[i], rightHand)])
                dp[i][(leftHand, word[i])] = \
                        min(dp[i-1][(leftHand, rightHand)] + dist(rightHand, word[i]), dp[i][(leftHand, word[i])])
            #print(word[i], dp[i], dist(leftHand, word[i]), dist(rightHand, word[i]), leftHand, rightHand, dp[i-1][(leftHand, rightHand)])
        return min(list(dp[lw-1].values()))