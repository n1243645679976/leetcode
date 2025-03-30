class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        ans = []
        for q in queries:
            iq = 0
            ip = 0
            flag = True
            while iq < len(q) and ip < len(pattern):
                # print(iq, ip)
                if q[iq] == pattern[ip]:
                    iq += 1
                    ip += 1
                elif ord(q[iq]) >= 65 and ord(q[iq]) <= ord('Z'):
                    flag = False
                    break
                else:
                    iq += 1
            for ind in range(iq, len(q)):
                if ord(q[ind]) >= 65 and ord(q[ind]) <= ord('Z'):
                    flag = False
                    break
            if not flag:
                ans.append(False)
            elif ip == len(pattern):
                ans.append(True)
            else:
                ans.append(False)
            
        return ans