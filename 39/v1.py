class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        que = []
        candidates.sort()
        def dfs(cand_ind, now):
            if now > target:
                return
            if now == target:
                ans.append(copy.deepcopy(que))
            
            for i in range(cand_ind, len(candidates)):
                que.append(candidates[i])
                dfs(i, now+candidates[i])
                que.pop()
        dfs(0, 0)
        return ans