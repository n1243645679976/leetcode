import collections
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        r = 0
        num, sgn = 0, 1
        for _s in s:
            if _s.isdigit():
                num *= 10
                num += ord(_s) - 48
                continue
            elif _s == '+':
                r += num * sgn
                num, sgn = 0, 1
            elif _s == '-':
                r += num * sgn
                num, sgn = 0, -1
            elif _s == '(':
                stack.append(r)
                stack.append(sgn)
                r = 0
                num, sgn = 0, 1
            elif _s == ')':
                r += num * sgn
                num, sgn = 0, 1
                r*=stack.pop()
                r+=stack.pop()
        r += num * sgn
        return r