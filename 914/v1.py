def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a, a)

class Solution(object):
    def hasGroupsSizeX(self, deck):
        """
        :type deck: List[int]
        :rtype: bool
        """
        q = Counter(deck)
        ans = q[deck[0]]
        for v in q.values():
            ans = gcd(ans, v)
            if ans == 1:
                return False
        return True
        