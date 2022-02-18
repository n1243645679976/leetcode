class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        stack = deque(["0"])
        for n in num:
            while n < stack[-1] and k > 0:
                stack.pop()
                k -= 1
            stack.append(n)
        while k:
            stack.pop()
            k -= 1
        while stack and stack[0] == "0":
            stack.popleft()
        if stack:
            return ''.join((stack))
        else:
            return "0"