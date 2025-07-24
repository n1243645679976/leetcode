class Solution:
    def longestValidParentheses(self, s: str) -> int:
        w = defaultdict(lambda: -1)
        now = 0
        ans = 0
        for i, _s in enumerate(s):
            # print(w)
            if _s == '(':
                now += 1
                if w[now] < 0:
                    w[now] = i
            else:
                w[now+1] = -1
                if now in w:
                    ans = max(i - w[now]+1, ans)
                    print(i, ans, now, w[now])
                now -= 1
        return ans
            