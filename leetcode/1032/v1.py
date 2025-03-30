class StreamChecker:

    def __init__(self, words: List[str]):
        self.d = defaultdict(set)
        self.mal = defaultdict(int)
        self.mil = defaultdict(lambda : 9999)
        for i in range(len(words)):
            self.d[words[i][-1]].add(words[i])
            self.mal[words[i][-1]] = max(len(words[i]), self.mal[words[i][-1]])
            self.mil[words[i][-1]] = min(len(words[i]), self.mil[words[i][-1]])
        self.now = []
    def query(self, letter: str) -> bool:
        self.now.append(letter)
        for i in range(self.mil[letter], self.mal[letter]+1):
            if ''.join(self.now[-i:]) in self.d[letter]:
                return True
        return False
        


# Your StreamChecker object will be instantiated and called as such:
# obj = StreamChecker(words)
# param_1 = obj.query(letter)