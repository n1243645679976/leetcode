class Solution(object):
    def scoreOfParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        indlist = []
        nums = [(-1, 0)]
        for i, c in enumerate(s):
            if c == '(':
                indlist.append(i)
            else:
                start_ind = indlist.pop()
                ind = -1
                to_add = []
                while nums[ind][0] > start_ind:
                    _, num = nums.pop()
                    to_add.append(num)
                if len(to_add) == 0:
                    sums = 1
                else:
                    sums = 2 * sum(to_add)
                nums.append((start_ind, sums))
        return sum([num for i, num in nums])