class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        e = sorted(envelopes, key=lambda x:(x[0], -x[1]))
        q = [-1]
        r = [-1]
        for i in range(len(e)):
            ind = bisect_left(q, e[i][1])
            if ind == len(q):
                if e[i][0] > r[-1] and e[i][1] > q[-1]:
                    q.append(e[i][1])
                    r.append(e[i][0])
            else:
                q[ind] = e[i][1]
                r[ind] = e[i][0] 
            #print(q, r)
        return len(q)-1