class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans = []
        q = []
        for s, e in intervals:
            q.append((abs(s+1), -s-1))
            q.append((abs(e+1), e+1))
        q = sorted(q)
        #print(q)
        s = 0
        for _, p in q:
            #print(p, s)
            if p < 0:
                if s == 0:
                    ans.append([-p-1])
                s += 1
            if p > 0:
                s -= 1
                if s == 0:
                    ans[-1].append(p-1)
        return ans
            
            