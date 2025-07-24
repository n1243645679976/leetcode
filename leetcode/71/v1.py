class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        a = path.split('/')
        ans_list = []
        ans = ''
        for k in a:
            if k == '..':
                if ans_list: ans_list.pop()
            elif k == '.' or k == '':
                pass
            else: ans_list.append(k)
        for k in ans_list:
            ans += '/' + k
        return ans if ans else '/'
                