class Solution:
    def myAtoi(self, s: str) -> int:
        if s == '':
            return 0
        for i in range(len(s)):
            if s[i] != ' ':
                break
        sign = 1
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1
        q = 0
        #print('#')
        for j in range(i, len(s)):
            #print(j, s[j])
            if not s[j].isdigit():
                break
            else:
                q *= 10
                q += ord(s[j]) - 48
        return min(max(q * sign, -2147483648), 2147483647)