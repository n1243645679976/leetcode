class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        return True if any(''.join(words[:i+1]) == s for i in range(len(words))) else False