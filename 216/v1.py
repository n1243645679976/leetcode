class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        comb = []
        def dfs(l, li, s):
            if l == k:
                if s == n:
                    ans.append(copy.deepcopy(comb))
                return
            for i in range(li+1,10):
                comb.append(i)
                dfs(l+1, i, s+i)
                comb.pop()
                
        dfs(0, 0, 0)
        return ans