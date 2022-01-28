class Node():
    def __init__(self):
        self.child = {}
        
class WordDictionary:
    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        word += '#'
        node = self.root
        for c in word:
            if c not in node.child:
                node.child[c] = Node()
            node = node.child[c]

    def search(self, word: str) -> bool:
        word += '#'
        def go_tree(node, ind):
            if ind == len(word):
                return True
            if word[ind] != '.':
                if word[ind] in node.child:
                    return go_tree(node.child[word[ind]], ind + 1)
                else:
                    return False
            else:
                for child in node.child.values():
                    if go_tree(child, ind + 1):
                        return True
                return False
        return go_tree(self.root, 0)