class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        lt = len(temperatures)
        t = temperatures
        days = [1000000 for i in range(102)]
        ans = deque()
        for q in range(lt - 1, -1, -1):
            days[t[q]] = q
            _min = min(days[t[q]+1:]) - q
            if _min > 100001:
                _min = 0
            ans.appendleft(_min)
        return ans
        
# v2 -> stack