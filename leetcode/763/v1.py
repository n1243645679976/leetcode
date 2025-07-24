class Solution(object):
    def partitionLabels(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        r = Counter(s)
        i = 0
        diff = 0
        c = Counter()
        ans = []
        while diff + i < len(s):
            if i != 0:
                split = True
                for key in c.keys():
                    if c[key] != r[key]:
                        split = False
                        break
                if split:
                    ans.append(i)
                    diff += i
                    c = Counter()
                    i = 0
            c[s[diff+i]] += 1
            i += 1
        if i != 0:
            ans.append(i)
        return ans
            