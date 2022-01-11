class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        if len(s) == 1:
            return []
        a = s[0]
        acc = 1
        st = 0
        ans = []
        for i in range(1, len(s)):
            if s[i] != a:
                a = s[i]
                if i - st >= 3:
                    ans.append([st, i-1])
                st = i
        if i - st >= 2:
            ans.append([st, i])
        return ans
                    
                