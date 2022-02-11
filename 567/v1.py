def check(a, b):
    for key in a.keys():
        if a[key] != b[key]:
            return False
    return True
class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) > len(s2):
            return False
        cs1 = Counter(s1)
        cs2 = Counter(s2[:len(s1)])
        if check(cs1, cs2):
            return True
        for i in range(len(s1), len(s2)):
            cs2[s2[i]] += 1
            cs2[s2[i-len(s1)]] -= 1
            if check(cs1, cs2):
                return True
            #print(cs1, cs2)
        return False
            