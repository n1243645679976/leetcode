class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        a = []
        for s, e in firstList:
            a.append(s)
            a.append(-e)
        for s, e in secondList:
            a.append(s)
            a.append(-e)
        
        a = sorted(a, key=lambda x: (abs(x), -x))
        # print(a)
        count = 0
        ans = []
        s = 0
        for _a in a:
            # print(s, _a, count)
            if _a >= 0:
                count += 1
                if count == 2:
                    s = _a
            if _a < 0:
                count -= 1
                if count == 1:
                    ans.append([s, -_a])
        return ans
                    