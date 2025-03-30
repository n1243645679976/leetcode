class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        return list(k for k, v in (Counter(s1.split()) + Counter(s2.split())).items() if v == 1)