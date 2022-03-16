class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        pushed = deque(pushed)
        popped = deque(popped)
        
        now = [-1]
        while pushed:
            #print('!', now)
            if popped[0] == now[-1]:
                now.pop()
                popped.popleft()
            else:
                q = pushed.popleft()
                now.append(q)
                
        while popped:
            #print(now)
            if popped[0] == now[-1]:
                now.pop()
                popped.popleft()
            else:
                break
        if len(now) == 1:
            return True
        return False