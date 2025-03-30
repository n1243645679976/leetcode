class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        q = ['!']
        for _s in s:
            if _s == '(' or _s == '{' or _s == '[':
                q.append(_s)
            else:
                r = q.pop()
                if _s == ')':
                    if r != '(':
                        return False
                if _s == '}':
                    if r != '{':
                        return False
                if _s == ']':
                    if r != '[':
                        return False
        if len(q) == 1:
            return True
        else:
            return False
            
                