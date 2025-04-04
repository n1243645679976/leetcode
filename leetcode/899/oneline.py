class Solution(object):
    def orderlyQueue(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        return ''.join(sorted(s)) if k > 1 else min(s[q:]+s[:q] for q in range(len(s)))