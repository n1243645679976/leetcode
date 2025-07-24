class Solution(object):
    def winnerSquareGame(self, n):
        """
        :type n: int
        :rtype: bool
        """
        ans = [False] * (n+1)
        sqs = []
        i = 1
        ans[1] = True
        while i * i <= n:
            sqs.append(i*i)
            i += 1
        for _n in range(n):
            for s in sqs:
                if _n + s > n:
                    break
                ans[_n + s] = ans[_n + s] or (not ans[_n])
                if _n + s == n and ans[_n+s]:
                    return True
        return ans[-1]
            