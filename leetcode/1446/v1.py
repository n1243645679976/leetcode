class Solution:
    def maxPower(self, s: str) -> int:
        pl = 1
        ps = s[0]
        ans = 1
        for q in s[1:]:
            #print(ans, ps)
            if q == ps:
                pl += 1
                ans = max(ans, pl)
            else:
                pl = 1
                ps = q
        return ans
    