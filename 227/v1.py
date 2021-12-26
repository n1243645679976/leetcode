class Solution:
    def calculate(self, s: str) -> int:
        a = [0]
        c = ['+']
        d = 0
        for _s in s:
            if _s == ' ':
                continue
            elif _s.isdigit():
                d *= 10
                d += ord(_s) - 48
            else:
                if c[-1] == '*':
                    a[-1] *= d
                    c.pop()
                elif c[-1] == '/':
                    a[-1] //= d
                    c.pop()
                else:
                    a.append(d)
                d = 0
                c.append(_s)
            
        if c[-1] == '*':
            a[-1] *= d
            c.pop()
        elif c[-1] == '/':
            a[-1] //= d
            c.pop()
        else:
            a.append(d)
        ans = a[0]
        for i in range(len(c)):
            if c[i] == '+':
                ans += a[i+1]
            if c[i] == '-':
                ans -= a[i+1]
        return ans
                    
                    
                
                