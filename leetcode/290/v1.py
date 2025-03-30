class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        q = s.split()
        if len(pattern) != len(q):
            return False
        rp2q = {}
        rq2p = {}
        for pp, qq in zip(pattern, q):
            if pp in rp2q and rp2q[pp] != qq:
                return False
            if qq in rq2p and rq2p[qq] != pp:
                return False
            rp2q[pp] = qq
            rq2p[qq] = pp
        return True