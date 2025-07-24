class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        town_judge = [0 for i in range(n+1)]
        for t in trust:
            town_judge[t[0]] -= 1
            town_judge[t[1]] += 1
        for i in range(1, n+1):
            if town_judge[i] == n - 1:
                return i
        return -1 
            
        