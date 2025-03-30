class Solution:
    def checkRecord(self, n: int) -> int:
        r = 1e9+7
        ans = [0,0,0,1,0,0,0] # 'A', 'L1', 'L2', 'P', 'AL1', 'AL2', 'AP'
        for i in range(n):
            ans = [(ans[1]+ans[2]+ans[3])%r, ans[3], ans[1], (ans[1]+ans[2]+ans[3])%r, (ans[0] + ans[-1])%r, ans[-3], (ans[0] + ans[-1] + ans[-2] + ans[-3])%r]
        return int(sum(ans) % r)
        