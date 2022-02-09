class Solution(object):
    def addToArrayForm(self, num, k):
        """
        :type num: List[int]
        :type k: int
        :rtype: List[int]
        """
        ans = []
        c = 0
        for n in range(len(num)-1, -1, -1):
            kk = k % 10
            if num[n] + kk + c >= 10:
                ans.append(num[n]+kk-10 + c)
                c = 1
            else:
                ans.append(num[n]+kk + c)
                c = 0
            k /= 10
        while k:
            if k % 10 + c >= 10:
                ans.append(k%10+c-10)
                c = 1
            else:
                ans.append(k%10+c)
                c = 0
            k /= 10
        if c:
            ans.append(1)
        ans.reverse()
        return ans
            
        